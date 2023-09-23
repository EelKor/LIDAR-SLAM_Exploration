clear; close all;

%% Define Wall
% 벽 좌표 지정 및 정의 부분
wall1 = [2 3 3 2; 2 2 5 5]; % 맨 좌측 아래기준으로 반시계방향 순서
wall2 = [6 7 7 6; 2 2 8 8];
wall3 = [4 5 5 4; 5 5 6 6];
wall4 = [4 5 5 4; 7 7 8 8];
SZthickness = 0.3;

figure(4)
I = imread("ENG_Three.pgm");
imshow("ENG_Three.pgm")
BW = imbinarize(I,'adaptive');

imshow(BW)
%% 
pgon1 = polyshape(wall1(1,:), wall1(2,:));
pgon2 = polyshape(wall2(1,:), wall2(2,:));
pgon3 = polyshape(wall3(1,:), wall3(2,:));
pgon4 = polyshape(wall4(1,:), wall4(2,:));

bl1 = GenerateBL(wall1,SZthickness);
bl2 = GenerateBL(wall2,SZthickness);
bl3 = GenerateBL(wall3,SZthickness);
bl4 = GenerateBL(wall4,SZthickness);

BoundaryLayer_pgon1 = polyshape(bl1(1,:), bl1(2,:));
BoundaryLayer_pgon2 = polyshape(bl2(1,:), bl2(2,:));
BoundaryLayer_pgon3 = polyshape(bl3(1,:), bl3(2,:));
BoundaryLayer_pgon4 = polyshape(bl4(1,:), bl4(2,:));

%% 
% Plot wall
figure(1);
hold on;
grid on;
plot(BoundaryLayer_pgon1); plot(pgon1,'FaceColor','red');
plot(BoundaryLayer_pgon2); plot(pgon2,'FaceColor','red');
plot(BoundaryLayer_pgon3); plot(pgon3,'FaceColor','red');
plot(BoundaryLayer_pgon4); plot(pgon4,'FaceColor','red');

xlim([0 10]); ylim([0 10])

%% Initilization
%node(1:10000) = struct('coord',[0 0],'parent',0,'cost',0);

% 람다값 설정
lam = 0.3;
q_init = [0,0]; % [x, y]
node(1).coord = q_init;
node(1).parent = 0;
node(1).cost = 0;

% 골인지점 영역 표시
q_goal = [8,8];
pathFind = 0; % 경로 찾은 횟수
r = 0.3;

circle_theta = linspace(0,2*pi,100);
circle_x = q_goal(1) + r*cos(circle_theta);
circle_y = q_goal(2) + r*sin(circle_theta);
goal_zone = polyshape(circle_x, circle_y);
scatter(q_goal(1), q_goal(2));
plot(goal_zone);

new_idx = 0;
%% Find q_new
count = 0;
tic

while(count < 10000)
    q_rand = 0 + 10 * rand(1,2);
    
    [idx,dist]= nearestNode(node, q_rand);
    q_near = node(idx).coord;
    q_new = q_near + (lam/dist).*(q_rand - q_near);
    
    % q_new 가 벽과 충돌하지 않으면 경로 tree 에 편입
    if(~isinterior(BoundaryLayer_pgon1,q_new(1), q_new(2)) && ...
            ~isinterior(BoundaryLayer_pgon2,q_new(1),q_new(2))) && ...
            ~isinterior(BoundaryLayer_pgon3,q_new(1),q_new(2)) && ...
            ~isinterior(BoundaryLayer_pgon4,q_new(1),q_new(2))
        
        % 인덱스 업데이트(노드번호)
        if(new_idx <= idx)
            new_idx = idx + 1;
        else
            new_idx = new_idx + 1;
        end
        node(new_idx).coord = q_new;
        node(new_idx).parent = idx;
        node(new_idx).cost = 0;

        % Goal 지점 주위에 도달하면 반복문 탈출
        if(isinterior(goal_zone, q_new(1), q_new(2)))

            disp("Path Find!");
            pathFind = pathFind+1;
            if(pathFind > 1)
                break;
            end
        end
    end
    count = count+1;
end

%% 트리 그래프 생성 

G = graph;
for i = 2:new_idx
    G = addedge(G,i,node(i).parent);
end

nodeXData = zeros(1,new_idx);
nodeYData = zeros(1,new_idx);
for i = 1:new_idx
    nodeXData(i) = node(i).coord(1);
    nodeYData(i) = node(i).coord(2);
end

% 그래프 그리기
p = plot(G, 'XData',nodeXData, 'YData',nodeYData);
hold off;

%% 최단경로 찾고 이외 경로는 삭제
% 최단거리 구하기
[ShortPath, d] = shortestpath(G,1,new_idx);
% 최단 거리 경로 이외 경로는 제거
[WP_node, WP_xy] = pruning(ShortPath,node);

 
%% 최단거리 경로 플로팅

figure(2);
hold on;
grid on;

plot(pgon1); 
plot(pgon2); 
plot(pgon3,'FaceColor','red');
plot(pgon4,'FaceColor','red');

plot(WP_xy(:,1), WP_xy(:,2));
plot(goal_zone);

%% WP 간소화
toc
