clear
close all

%% StaeSpace Configuration
ss = stateSpaceSE2;
sv = validatorOccupancyMap(ss);
image = imread("901.pgm");

%% Noise Remove (Steel Door)

image = medfilt2(image);
%% Image_Temp_Grid_MaO()

image_temp = image;
image_temp = uint8((image_temp>253).*255);
%imageCropped_temp = image_temp(500:1400,750:2040);
imageNorm_temp = double(image_temp)/255;
imageOccupancy_temp = 1 - imageNorm_temp;

map_temp = occupancyMap(imageOccupancy_temp,20);
sv.Map = map_temp;

sv.ValidationDistance = 0.01;

ss.StateBounds = [map_temp.XWorldLimits; map_temp.YWorldLimits; [-pi pi]];

planner = plannerRRTStar(ss,sv, ...
          ContinueAfterGoalReached=true, ...
          MaxIterations=30000, ...
          MaxConnectionDistance=0.5);

map_temp.show
hold on

%% Original Image Grid Map
ss = stateSpaceSE2;

sv = validatorOccupancyMap(ss);

% Gaussian Filter
image = imgaussfilt(image,2);

% load 811_1.pgm
image = uint8((image>253).*255); % Gray Scale Image Conversion as BW Image
% imshow(image)
imageNorm = double(image)/255;
%imageCropped = imageCropped(500:1400,750:2040);
imageOccupancy = 1 - imageNorm;

map = occupancyMap(imageOccupancy,20);
%map.show

sv.Map = map;

sv.ValidationDistance = 0.01;

ss.StateBounds = [map.XWorldLimits; map.YWorldLimits; [-pi pi]];

planner = plannerRRTStar(ss,sv, ...
          ContinueAfterGoalReached=false, ...
          MaxIterations=300000, ...
          MaxConnectionDistance=0.3);

start = [52.0 46.0 0];
goal = [58.5 18.0 0];

rng(100,'twister') % repeatable result
[pthObj,solnInfo] = plan(planner,start,goal);

% RRT Star Node Plot
plot(pthObj.States(:,1),pthObj.States(:,2),'r-','LineWidth',2)
% plot(solnInfo.TreeData(:,1),solnInfo.TreeData(:,2),'.-')

%% RRT Star Node Array Generate
pthNode(:,1) = pthObj.States(:,1);
pthNode(:,2) = pthObj.States(:,2);
pthNode = pthNode';

%% Path Cost Before Line Interpolation
distcost_RRT = distance_cost(pthNode);

fprintf('선형보간 전 Cost는 %d 이다.',distcost_RRT);

%% Line InterPolation 함수 설명  
% [InterPolArray,Lip_Array] = lineIntp(nodeArray,map_Resolution,Coll_Resolution,size_Row,imageOccupancy)
% InterPolArray는 pthNode 배열에서 선형 보간된 Node의 Index를 딴 배열이다.
% LIP_Array는 선형 보간된 배열을 좌표값으로 변환한 2XN 행열이다.
% Coll_Resolution은 Obstacle을 판정하기 위한 Node와 Node 사이에 생성할 판정 Node의 갯수이다. 즉
% Coll_Resolition이 10이면 Node와 Node 사이의 Obstacle을 판정하기 위해 생성되는 Node들은 10개란
% 의미이다.
size_Row = length(imageOccupancy(:,1)) ;
Coll_Resolution = 5;
%% First Line Interpolation

[InterPolArray,LIP_Array] = lineIntp(pthNode,map.Resolution,Coll_Resolution,size_Row,imageOccupancy);
[Norm_1,Vector_1,Theta_rad_1,Theta_deg_1] = Control_Signal(InterPolArray,LIP_Array);
distcost_LIP1 = sum(Norm_1);

fprintf('1차 선형보간 후 Cost는 %d 이다.',distcost_LIP1);
% plot(LIP_Array(1,:),LIP_Array(2,:),'b-','LineWidth',2) % 1차 선형보간 Plot

%% Second Line Interpolation
%[InterPolArray,LIP_Array] = lineIntp(LIP_Array,map.Resolution,Coll_Resolution,size_Row,imageOccupancy);
%[Norm_2,Vector_2,Theta_rad_2,Theta_deg_2] = Control_Signal(InterPolArray,LIP_Array);
%distcost_LIP2 = sum(Norm_2);

%fprintf('2차 선형보간 후 Cost는 %d 이다.',distcost_LIP2);
% plot(LIP_Array(1,:),LIP_Array(2,:),'g-','LineWidth',2) % 2차 선형보간 Plot
% map.show

%% Third Line InterPolation
%[InterPolArray,LIP_Array] = lineIntp(LIP_Array,map.Resolution,Coll_Resolution,size_Row,imageOccupancy);
%[Norm_3,Vector_3,Theta_rad_3,Theta_deg_3] = Control_Signal(InterPolArray,LIP_Array);
LIP_Array_X(1,:) = LIP_Array(1,:) - LIP_Array(1,1);
LIP_Array_Y(1,:) = LIP_Array(2,:) - LIP_Array(2,1);

LIP_Array_X = LIP_Array_X - LIP_Array_X(1,end);
LIP_Array_X = fliplr(LIP_Array_X);

LIP_Array_Y = LIP_Array_Y - LIP_Array_Y(1,end);
LIP_Array_Y = fliplr(LIP_Array_Y);

%distcost_LIP3 = sum(Norm_3);
%Norm_3 = Norm_3';


%fprintf('3차 선형보간 후 Cost는 %d 이다.',distcost_LIP3);
plot(LIP_Array(1,:),LIP_Array(2,:),'b-','LineWidth',2) % 3차 선형보간 Plot
%%

a = ~isempty(Trajectory_X);
b = ~isempty(Trajectory_Y);
if a == 1 && b == 1
    plot(Trajectory_X+(102.4/2),Trajectory_Y-(102.4/2),'g-','Linewidth',2);
end
