function [Norm,Vector,Theta_rad,Theta_deg] = Control_Signal(InterPolArray,LIP_Array)

% Vector Generate

for c = 2:length(InterPolArray)
    Vector(c-1,1) = LIP_Array(1,c) - LIP_Array(1,c-1);
    Vector(c-1,2) = LIP_Array(2,c) - LIP_Array(2,c-1);
    Norm(c-1,1) = norm(Vector(c-1,:));
    Com_Vector(1,c-1) = complex(Vector(c-1,1),Vector(c-1,2));
    Theta_rad_temp(1,c-1) = angle(Com_Vector(1,c-1));
end
Theta_rad(1,1) = Theta_rad_temp(1,1);

for k = 2:length(Vector)
    Theta_rad(1,k) = Theta_rad_temp(1,k) - Theta_rad_temp(1,k-1);
end
Theta_rad = -Theta_rad;

Theta_deg(1,:) = rad2deg(Theta_rad(1,:));

%Norm과 Dot Product를 이용한 Theta 구하는 Code 
% Theta Init (Heading Angle)
% X_Direct = [1 0];
%First Theta Calculate
% Dot_Product = dot(X_Direct,Vector(1,:));
% norm_1 = norm(X_Direct);
% norm_2 = Norm(1,1);
% Theta_temp = acos(Dot_Product / (norm_1 * norm_2));
% Theta_temp = max(min(dot(X_Direct,Vector(1,:))/(norm(X_Direct)*Norm(1,1))),-1);
% Theta(1,1) = rad2deg(Theta_temp);
% for t = 1:length(Vector)
%     if t == 1
%         continue
%     else
%         Dot_Product = dot(Vector(t-1,:),Vector(t,:));
%         norm_1 = Norm(t-1);
%         norm_2 = Norm(t);
%         Theta_temp = acos(Dot_Product / (norm_1 * norm_2));
%         Theta(1,t) = rad2deg(Theta_temp);
%     end
% end
% Theta_temp = max(min(dot(X_Direct,Vector(1,:))/(norm(X_Direct)*Norm(1,1))),-1);
% Theta(1,1) = rad2deg(Theta_temp);

end