function [minIdx,minDist] = nearestNode(node, q_rand)

[~, sz] = size(node);
x0 = q_rand(1); y0 = q_rand(2);
minIdx = 1; 
minDist = sqrt((node(1).coord(1) - x0)^2 + (node(1).coord(2) - y0)^2);

for i = 2:sz
    distence = sqrt((node(i).coord(1) - x0)^2 + (node(i).coord(2) - y0)^2);

    if(distence < minDist) 
        minDist = distence;
        minIdx = i;
    end
end
