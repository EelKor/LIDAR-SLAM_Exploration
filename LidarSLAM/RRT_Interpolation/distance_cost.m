function [distcost] = distance_cost(LIP_Array)
%UNTITLED2 이 함수의 요약 설명 위치
%   자세한 설명 위치
distcost = 0;
for i = 2:length(LIP_Array)
    dist = sqrt((LIP_Array(1,i-1) - LIP_Array(1,i))^2 + (LIP_Array(2,i-1) - LIP_Array(2,i))^2);
    distcost = dist + distcost;
end