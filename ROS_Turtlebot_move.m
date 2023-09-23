% 터틀봇 주행 스크립트 
% VMWare Gazebo + ROS1 noetic
% ROS Toolbox 이용

clear; clc; close all;

% Tubtlebot IP Address, ROS_MASTER_URI
ipadd = "http://192.168.206.128:11311";

% ROS 네트워크 연결
rosinit(ipadd);

% 속도 설정
V_GO = 0.5; V_STOP = 0; V_BACK = -0.5;

% 속도 명령 퍼블리셔 설정
robotCMD = rospublisher("/cmd_vel","DataFormat","struct");
velMsg = rosmessage(robotCMD);

% 라이다 Subscriber 설정
lidarSub = rossubscriber("/scan","DataFormat","struct");
figure(1)


tic;
while toc < 100 % 100초 동안 스크립트 실행
    velMsg.Linear.X = V_GO;
    send(robotCMD,velMsg)
    scanMsg = receive(lidarSub);
    rosPlot(scanMsg)
    pause(3)

    velMsg.Linear.X = V_STOP;
    send(robotCMD,velMsg)
    scanMsg = receive(lidarSub);
    rosPlot(scanMsg)
    pause(3)
    
    velMsg.Linear.X = V_BACK;
    send(robotCMD,velMsg)
    scanMsg = receive(lidarSub);
    rosPlot(scanMsg)
    pause(3)
end

rosshutdown
