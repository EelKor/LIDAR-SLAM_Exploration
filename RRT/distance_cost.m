function [distcost] = distance_cost(q_near,q_new)
%UNTITLED2 이 함수의 요약 설명 위치
%   자세한 설명 위치
distcost = sqrt((q_new(1) - q_near(1))^2 + (q_new(2) - q_near(2))^2);