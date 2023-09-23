clear;
clc
 EdgeTable = table([1 2; 2 3; 3 5; 4 5],'VariableNames',{'EndNodes'})
  NodeTable = table({'a'; 'b'; 'c'; 'd';'e'},'VariableNames',{'Name'})
  G = graph(EdgeTable, NodeTable)
  plot(G)