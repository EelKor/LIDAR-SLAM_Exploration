function rosmsgOut = Pose2D(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.X = double(slBusIn.X);
    rosmsgOut.Y = double(slBusIn.Y);
    rosmsgOut.Theta = double(slBusIn.Theta);
end
