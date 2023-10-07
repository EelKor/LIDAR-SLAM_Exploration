function [InterPolArray,LIP_Array] = lineIntp(nodeArray,map_Resolution,Coll_Resolution,size_Row,imageOccupancy)

%% Variable Init
sNode = 1;
InterPolArray = [1];
gNode = 2;
Nodenum = length(nodeArray);

%% Main Line InterPolation Section
while true

    collx_mat = linspace(nodeArray(1,sNode),nodeArray(1,gNode)...
        ,(gNode-sNode)*Coll_Resolution);
    colly_mat = linspace(nodeArray(2,sNode),nodeArray(2,gNode)...
        ,(gNode-sNode)*Coll_Resolution);    

    for i = 1:length(collx_mat)
        coll_mat_col(i) = round(collx_mat(i)*map_Resolution);
        coll_mat_row(i) = size_Row - round(colly_mat(i)*map_Resolution);
        coll_mat_val(i) = imageOccupancy(coll_mat_row(i),coll_mat_col(i)); 
    end

    coll_sum = sum(coll_mat_val);

    if gNode == Nodenum
        InterPolArray = [InterPolArray gNode];
        break
    elseif coll_sum == 0
        gNode = gNode + 1;
    else
        sNode = gNode - 1;
        if sNode == InterPolArray(1,end)
            gNode = gNode + 1;
        else
            InterPolArray = [InterPolArray sNode];
        end
    end

    % Matrix Init
    collx_mat = [];
    colly_mat = [];
    coll_mat_val = [];
    coll_sum = 0;
end

%% Line InterPolation Node Array Section

LIP_Array = [ ; ];

for k = 1:length(InterPolArray)
    LIP_Array(1,k) = nodeArray(1,InterPolArray(k));
    LIP_Array(2,k) = nodeArray(2,InterPolArray(k));
end

end