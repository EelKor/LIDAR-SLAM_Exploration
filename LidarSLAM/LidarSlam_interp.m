classdef LidarSlam_interp < matlab.System
    % 
    %
    % 
    
    % Public, tunable properties
    properties
        maxLidarRange = 25;
        mapResolution = 20;
        maxNumScans = 15;
    end
    
    properties(DiscreteState)
    end
    
    % Pre-computed constants
    properties(Access = private)
        slamAlg = lidarSLAM(20);
    end
    
    methods(Access = protected)
        function setupImpl(obj)
            % Give computing constants
            % Tune these parameters according to your system and environment 
            LoopClosureThreshold = 2;
            LoopClosureSearchRadius = 2;
           
            obj.slamAlg = lidarSLAM(obj.mapResolution, obj.maxLidarRange,obj.maxNumScans);
            obj.slamAlg.LoopClosureThreshold = LoopClosureThreshold;
            obj.slamAlg.LoopClosureSearchRadius = LoopClosureSearchRadius;
        end
        
        function [slamStatus,pose, mapData] = stepImpl(obj,ranges,angles)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            scan = lidarScan(ranges,angles);
            if (obj.slamAlg.PoseGraph.NumNodes<1000)
            %  Its a  design choise, more nodes mean you will get finer map but atan expnese on increase computational load
            
                addScan(obj.slamAlg, scan); % adding most recent scans to the slamAlg ie lidarSLAM algortithm
                slamStatus = int8(0);
            else
                slamStatus = int8(1);
            end

            nodes = obj.slamAlg.PoseGraph.NumNodes;
        
            [scans,poses] = scansAndPoses(obj.slamAlg);
            pose=poses(end,:);
          
            map = buildMap(scans, poses, obj.mapResolution, obj.maxLidarRange);
            mapData = occupancyMatrix(map);

            figure(1)
            hold on;
            show(map)
            % Ploting Start Point, Goal Point, Current Position
            scatter(0,0,"square",'filled','CData',[0 0 1]);
            scatter(pose(1),pose(2),'filled','CData',[1 0 0]);

            % Draw heading
            d = 1;
            line([pose(1) pose(1)+d*cos(pose(3))], [pose(2) pose(2)+d*sin(pose(3))],'Color','blue');
            axis([-10 10 -10 10]);
        end
        
        
        
        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
        
        function [out1, out2, out3] = getOutputSizeImpl(~)
            % Return size for each output port
            out1 = [1 1];
            out2 = [1 3];
            out3 = [1000 1000]; % ask for variable size array
        end
        
        function [out1, out2, out3] = getOutputDataTypeImpl(~)
            % Return data type for each output port
            out1 = "int8";
            out2 = "double";
            out3 = "double";
        end
        
        function [out1, out2, out3] = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            out1 = false;
            out2 = false;
            out3 = false;
        end
        
        function [out1, out2, out3] = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            out1 = true;
            out2 = true;
            out3 = false;
        end
         
        function sts = getSampleTimeImpl(obj)
            % Define sample time type and parameters
            sts = obj.createSampleTime("Type", "Discrete", ...
                "SampleTime", 0.5);
        end    
        
    end
    
    
end
