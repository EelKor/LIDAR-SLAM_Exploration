clc; clear; close all;

ss = stateSpaceSE2;
sv = validatorOccupancyMap(ss);
%%
%rng('default');
%map = mapClutter(20,'MapSize',[50 50],'MapResolution',1);
load("exampleMaps.mat")
map = occupancyMap(complexMap,10);

sv.Map = map;
sv.ValidationDistance = 0.01;
ss.StateBounds = [map.XWorldLimits; map.YWorldLimits; [-pi pi]];
show(map)
%%
startrrt = [1 1 0];
goalrrt = [10 11 0];
start_2 = [1 10];
goal_2 = [11 1];
startPose = [1 1 pi/4]; % [meters, meters, radians]
goalPose = [50 50 5 *pi/4];

%%

planner_Astar = plannerAStarGrid(map);

planner_rrtStar = plannerRRTStar(ss,sv, ...
          ContinueAfterGoalReached=false, ...
          MaxIterations=2500, ...
          MaxConnectionDistance=0.3);
%%

figure(1)
tic;
plan(planner_Astar,start_2,goal_2);
Astar_time = toc;
show(planner_Astar)
fprintf("Astar_time = %d\n", Astar_time);

figure(3)
rng(100,'twister') % repeatable result
tic;
[pthObj,solnInfo] = plan(planner_rrtStar,startrrt,goalrrt);
rrtStar_time = toc;
fprintf("rrtstar_time = %d\n", rrtStar_time);
map.show
hold on
% Tree expansion
plot(solnInfo.TreeData(:,1),solnInfo.TreeData(:,2),'.-')
% Draw path
plot(pthObj.States(:,1),pthObj.States(:,2),'r-','LineWidth',2)
title("RRT* Path Planner")