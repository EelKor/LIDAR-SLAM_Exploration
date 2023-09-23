%% Define Wall boundary layer
% ----------------------------
% [Parameters]
% wall: 4x2 matrix
% thickness 1x1 double
% -----------------------------
% [OUTPUTS]
% bl: 4x2 matrix

function bl = GenerateBL(wall,thickness)

wallx = wall(1,:);
wally = wall(2,:);

bl = [wallx(1)-thickness, wallx(2)+thickness, wallx(3)+thickness, wallx(4)-thickness; ...
      wally(1)-thickness, wally(2)-thickness, wally(3)+thickness, wally(4)+thickness];

