function [WP, WP_xy] = pruning(ShortPath, node)

WP_xy = [node(1).coord(1) node(1).coord(2)];

for i = 2:length(ShortPath)
    WP_xy = [WP_xy; [node(ShortPath(i)).coord(1) node(ShortPath(i)).coord(2)]];
end

WP = ShortPath;
