function slBusOut = MapMetaData(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    currentlength = length(slBusOut.MapLoadTime);
    for iter=1:currentlength
        slBusOut.MapLoadTime(iter) = bus_conv_fcns.ros.msgToBus.ros.Time(msgIn.MapLoadTime(iter),slBusOut(1).MapLoadTime(iter),varargin{:});
    end
    slBusOut.MapLoadTime = bus_conv_fcns.ros.msgToBus.ros.Time(msgIn.MapLoadTime,slBusOut(1).MapLoadTime,varargin{:});
    slBusOut.Resolution = single(msgIn.Resolution);
    slBusOut.Width = uint32(msgIn.Width);
    slBusOut.Height = uint32(msgIn.Height);
    currentlength = length(slBusOut.Origin);
    for iter=1:currentlength
        slBusOut.Origin(iter) = bus_conv_fcns.ros.msgToBus.geometry_msgs.Pose(msgIn.Origin(iter),slBusOut(1).Origin(iter),varargin{:});
    end
    slBusOut.Origin = bus_conv_fcns.ros.msgToBus.geometry_msgs.Pose(msgIn.Origin,slBusOut(1).Origin,varargin{:});
end
