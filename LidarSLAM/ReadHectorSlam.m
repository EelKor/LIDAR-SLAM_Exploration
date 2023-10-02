%clear
ROS_MASTER_URI = '192.168.101.128';

rosinit(ROS_MASTER_URI);

% /map 토픽을 Subscribe하는 Subscriber 생성
mapSub = rossubscriber('/map', 'nav_msgs/OccupancyGrid');
% /slam_out_pose 토픽을 Subscribe하는 Subscriber 생성
poseSub = rossubscriber('/slam_out_pose', 'geometry_msgs/PoseStamped');

% 그래프 초기화
figure;
hold on;
title('/map 토픽 데이터');

while true
    % /map 토픽으로부터 메시지를 받음
    mapMsg = receive(mapSub);

    % 지도 데이터를 가져옴
    map = readOccupancyGrid(mapMsg);

    % 지도 데이터를 플로팅
    show(map);
    poseMsg = receive(poseSub);
    scatter(poseMsg.Pose.Position.X, poseMsg.Pose.Position.Y,'red')
    % x, y 축의 범위를 조절 (예: x는 -10에서 10, y는 -5에서 5)
    axis([-5 5 -5 5]);
    % 그래프 업데이트
        a
    drawnow;

    % 1초마다 업데이트
    pause(1);
end

% ROS 연결 종료
rosshutdown;
