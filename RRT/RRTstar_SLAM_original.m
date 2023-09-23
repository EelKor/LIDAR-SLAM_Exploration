clear; close all;

%% 시작지점, 도착지점 좌표 설정

start = [25 20 0];
goal = [38 72 0];

%% Original RRT*
% SLAM 데이터에 RRT* 사용한 결과

ss = stateSpaceSE2;
sv = validatorOccupancyMap(ss);

% pgm 불러오기 및 크롭

I = imread('BW_ENG3.pgm');
cropI = imcrop(I,[709 295 1338 941]);

% occupancyMap 작성
imageNorm = double(cropI)/255;
imageOccupancy = 1 - imageNorm;

map = occupancyMap(imageOccupancy,10);

sv.Map = map;
sv.ValidationDistance = 0.01;
ss.StateBounds = [map.XWorldLimits; map.YWorldLimits; [-pi pi]];
map.show;

% Path planning
planner = plannerRRTStar(ss,sv, ...
          ContinueAfterGoalReached=false, ...
          MaxIterations=100000, ...
          MaxConnectionDistance=0.3);

rng(100,'twister') % repeatable result
[pthObj,solnInfo] = plan(planner,start,goal);
map.show

figure(1)
map.show
title("RRT*")
hold on
% Tree expansion
plot(solnInfo.TreeData(:,1),solnInfo.TreeData(:,2),'.-')
% Draw path
plot(pthObj.States(:,1),pthObj.States(:,2),'r-','LineWidth',2)