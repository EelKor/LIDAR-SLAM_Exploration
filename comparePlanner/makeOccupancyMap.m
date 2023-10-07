clear;
empty = zeros(60,60,'logical')
empty(:,1) = 1
empty(1,:) = 1
empty(:,end) = 1
empty(end,:) = 1

map_2x2 = empty;
for i = 1:30
    for j=1:30
        map_2x2(2*i-1,2*j-1) = 1;
    end
end

map_4x4 = empty;
for i=1:15
    for j=1:15
        map_4x4((4*i-3), (4*j-3)) = 1
    end
end