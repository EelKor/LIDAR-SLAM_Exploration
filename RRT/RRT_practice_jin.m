clear; close all;

%% Define Wall
% 벽 좌표 지정 및 정의 부분
wall1 = [2 3 3 2; 2 2 5 5]; % 맨 좌측 아래기준으로 반시계방향 순서
wall2 = [6 7 7 6; 2 2 8 8];
wall3 = [4 5 5 4; 5 5 6 6];
wall4 = [4 5 5 4; 7 7 8 8];
SZthickness = 0.3;

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

% 람다값 설정
lam = 0.3;
q_init = [0,0]; % [x, y]

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

G = graph;
xy = [0 0];
tree = [q_init];
new_idx = 0;
%% Find q_new
count = 0;
tic

nodes(1).coord = [0 0];
nodes(1).cost = 0;
nodes(1).parent = 0;

while(count < 10000)
    q_rand = 0 + 10 * rand(1,2);
    [idx,dist]= nearestNode(tree, q_rand); %q_near 찾는 Code
    q_near = tree(idx,:);
    q_new = q_near + (lam/dist).*(q_rand - q_near);
    % q_new 가 벽과 충돌하지 않으면 경로 tree 에 편입
    if(~isinterior(BoundaryLayer_pgon1,q_new(1), q_new(2)) && ...
            ~isinterior(BoundaryLayer_pgon2,q_new(1),q_new(2))) && ...
            ~isinterior(BoundaryLayer_pgon3,q_new(1),q_new(2)) && ...
            ~isinterior(BoundaryLayer_pgon4,q_new(1),q_new(2))
  
        tree = [tree; q_new];
        
        % 노드 생성
        if(new_idx <= idx)
            new_idx = idx + 1;
        else
            new_idx = new_idx + 1;
        end
        nodes(new_idx).XData = q_new(1);
        nodes(new_idx).YData = q_new(2);
        nodes(new_idx).cost = nodes(idx).cost + distance_cost(q_near,q_new);
        nodes(new_idx).parent = idx;
        
        xy = [xy; q_new];
        %scatter(q_new(1),q_new(2));
        %line([q_near(1), q_new(1)],[q_near(2), q_new(2)]);
        %drawnow limitrate;
        
        % Goal 지점 주위에 도달하면 반복문 탈출
        if(isinterior(goal_zone, q_new(1), q_new(2)))

            disp("Path Find!");
            pathFind = pathFind+1;
            if(pathFind > 2)
                break;
            end
        end
    end
    count = count+1;
end


% 그래프 그리기
p = plot(G,'XData',xy(:,1),'YData',xy(:,2));
hold off;

%% 
q_end = nodes(new_idx);

while q_end.parent ~= 0
    start = q_end.parent;
    line([q_end.coord(1), nodes(start).coord(1)], [q_end.coord(2), nodes(start).coord(2)], 'Color', 'b', 'LineWidth', 2);
    hold on
    q_end = nodes(start);

end

sentence = ['Path Total Distance Is ',num2str(nodes(new_idx).cost),'(m).'];
disp(sentence);

% % 최단거리 구하기
% [ShortPath, d] = shortestpath(G,1,new_idx);
% % 최단 거리 경로 이외 경로는 제거
% [WP_node, WP_xy] = pruning(ShortPath,xy);

% figure(2);
% hold on;
% grid on;
% 
% plot(pgon1); 
% plot(pgon2); 
% plot(pgon3,'FaceColor','red');
% plot(pgon4,'FaceColor','red');
% 
% plot(WP_xy(:,1), WP_xy(:,2));
% plot(goal_zone);
% 
% toc
