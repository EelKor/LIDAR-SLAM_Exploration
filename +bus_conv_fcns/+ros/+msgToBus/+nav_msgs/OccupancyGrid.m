function slBusOut = OccupancyGrid(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021-2022 The MathWorks, Inc.
    currentlength = length(slBusOut.Header);
    for iter=1:currentlength
        slBusOut.Header(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header(iter),slBusOut(1).Header(iter),varargin{:});
    end
    slBusOut.Header = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header,slBusOut(1).Header,varargin{:});
    currentlength = length(slBusOut.Info);
    for iter=1:currentlength
        slBusOut.Info(iter) = bus_conv_fcns.ros.msgToBus.nav_msgs.MapMetaData(msgIn.Info(iter),slBusOut(1).Info(iter),varargin{:});
    end
    slBusOut.Info = bus_conv_fcns.ros.msgToBus.nav_msgs.MapMetaData(msgIn.Info,slBusOut(1).Info,varargin{:});
    maxlength = length(slBusOut.Data);
    recvdlength = length(msgIn.Data);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Data', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Data_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Data_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.Data = int8(msgIn.Data(1:slBusOut.Data_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.Data(recvdlength+1:maxlength) = 0;
    end
end
