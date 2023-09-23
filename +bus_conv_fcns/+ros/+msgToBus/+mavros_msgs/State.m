function slBusOut = State(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    currentlength = length(slBusOut.Header);
    for iter=1:currentlength
        slBusOut.Header(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header(iter),slBusOut(1).Header(iter),varargin{:});
    end
    slBusOut.Header = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header,slBusOut(1).Header,varargin{:});
    slBusOut.Connected = logical(msgIn.Connected);
    slBusOut.Armed = logical(msgIn.Armed);
    slBusOut.Guided = logical(msgIn.Guided);
    slBusOut.ManualInput = logical(msgIn.ManualInput);
    slBusOut.Mode_SL_Info.ReceivedLength = uint32(strlength(msgIn.Mode));
    currlen  = min(slBusOut.Mode_SL_Info.ReceivedLength, length(slBusOut.Mode));
    slBusOut.Mode_SL_Info.CurrentLength = uint32(currlen);
    slBusOut.Mode(1:currlen) = uint8(char(msgIn.Mode(1:currlen))).';
    slBusOut.SystemStatus = uint8(msgIn.SystemStatus);
end
