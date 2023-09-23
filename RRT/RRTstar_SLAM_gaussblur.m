clear
%% staeSoaceSE2 선언

ss = stateSpaceSE2;
sv = validatorOccupancyMap(ss);

%% pgm 불러오기 및 크롭

I = imread('BW_ENG3.pgm');
cropI = imcrop(I,[709 295 1338 941]);
figure(3)
imshow(I)

%% 가우시안 블러 및 Threshold
figure(4)
blurI = imgaussfilt(cropI,4);
imshow(blurI)
blurI = uint8((blurI>253).*255);

%% occupancyMap 작성
imageNorm = double(blurI)/255;
imageOccupancy = 1 - imageNorm;

imageNormOrigin = double(cropI)/255;
imageOccupancyOrigin = 1 - imageNormOrigin;

map = occupancyMap(imageOccupancy,10);
mapOrigin = occupancyMap(imageOccupancyOrigin,10);

sv.Map = map;
sv.ValidationDistance = 0.01;
ss.StateBounds = [map.XWorldLimits; map.YWorldLimits; [-pi pi]];
map.show;

%% path planning

planner = plannerRRTStar(ss,sv, ...
          ContinueAfterGoalReached=false, ...
          MaxIterations=100000, ...
          MaxConnectionDistance=0.3);

start = [25 20 0];
goal = [38 72 0];

rng(100,'twister') % repeatable result
[pthObj,solnInfo] = plan(planner,start,goal);
map.show

figure(1)
mapOrigin.show
hold on
% Tree expansion
plot(solnInfo.TreeData(:,1),solnInfo.TreeData(:,2),'.-')
% Draw path
plot(pthObj.States(:,1),pthObj.States(:,2),'r-','LineWidth',2)