clear; close all;
clc;

load 2023-08-28.mat
mapData = out.MapData.signals.values(:,:,137);
[row , ~] = find(isnan(mapData));
cMap = mapData(1:row-1,1:row-1);
map = occupancyMap(cMap,20);
map.GridLocationInWorld = [-10 -10];

figure(1)
show(map)
hold on;

% [known_x,known_y] = find(cMap < 0.1);
% worldcoord = [];
% for ii = 1:length(known_x)
%     worldcoord = [worldcoord; grid2world(map,[known_x(ii),known_y(ii)])];
% end
% scatter(worldcoord(:,1),worldcoord(:,2))


sobel = edge(cMap);
[idx_x,idx_y] = find(sobel == 1);
edgeCoord = [idx_x, idx_y];
frontier = [];
for ii = 1:length(edgeCoord)
    x = edgeCoord(ii,1); y = edgeCoord(ii,2);
    xl = x-1; yl = y;
    xr = x+1; yr = y;
    xu = x; yu = y-1;
    xd = x; yd = y+1;
    if(cMap(x,y) > 0.1)
        continue
    end
    

    if(cMap(xl,yl) > 0.49 && cMap(xl,yl) < 0.51) % Unknown area
        cord = grid2world(map,[x,y]);
        frontier = [frontier; cord(1),cord(2)];
       
    elseif(cMap(xr,yr) > 0.49 && cMap(xr,yr) < 0.51)
        cord = grid2world(map,[x,y]);
        frontier = [frontier; cord(1),cord(2)];
    elseif(cMap(xu,yu) > 0.49 && cMap(xu,yu) < 0.51)
        cord = grid2world(map,[x,y]);
        frontier = [frontier; cord(1),cord(2)];
    elseif(cMap(xd,yd) > 0.49 && cMap(xd,yd) < 0.51)
        cord = grid2world(map,[x,y]);
        frontier = [frontier; cord(1),cord(2)];
    end
end
scatter(frontier(:,1), frontier(:,2),'filled','CData',[1 0 0])
figure(2); imshow(sobel)
