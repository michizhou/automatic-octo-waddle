% simarray = importdata('Book3.xlsx');
% difscores = zeros(60,8);

% for m = 1:7
%     for n = 1:7
%         difscores(m,n) = dtw(simarray(m,:),simarray(n,:));
%     end
% end
% for m = 8:13
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+7,:));
%     end
% end
% for m = 14:19
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+13,:));
%     end
% end
% for m = 20:25
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+19,:));
%     end
% end
% for m = 26:32
%     for n = 1:7
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+25,:));
%     end
% end
% for m = 33:37
%     for n = 1:5
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+32,:));
%     end
% end
% for m = 38:43
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+37,:));
%     end
% end
% for m = 44:49
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+43,:));
%     end
% end
% for m = 50:55
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+49,:));
%     end
% end
% for m = 58:63
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+57,:));
%     end
% end
% for m = 64:69
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+63,:));
%     end
% end
% for m = 70:75
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+69,:));
%     end
% end
% for m = 76:81
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+75,:));
%     end
% end
% for m = 82:87
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+81,:));
%     end
% end
% for m = 88:93
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+87,:));
%     end
% end
% for m = 94:99
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+93,:));
%     end
% end
% for m = 100:105
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+99,:));
%     end
% end
% for m = 106:111
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+105,:));
%     end
% end
% for m = 112:118
%     for n = 1:7
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+111,:));
%     end
% end
% for m = 119:124
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+118,:));
%     end
% end
% for m = 125:130
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+124,:));
%     end
% end
% for m = 131:136
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+130,:));
%     end
% end
% for m = 137:142
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+136,:));
%     end
% end
% for m = 143:148
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+142,:));
%     end
% end
% for m = 149:154
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+148,:));
%     end
% end
% for m = 155:160
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+154,:));
%     end
% end
% for m = 161:166
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+160,:));
%     end
% end

% for m = 1:7
%     for n = 1:7
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+7,:));
%     end
% end
% for m = 15:20
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+20,:));
%     end
% end
% for m = 27:32
%     for n = 1:5
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+32,:));
%     end
% end
% for m = 38:43
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+43,:));
%     end
% end
% for m = 50:56
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+56,:));
%     end
% end
% for m = 63:67
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+67,:));
%     end
% end
% for m = 74:79
%     for n = 1:7
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+79,:));
%     end
% end
% for m = 87:92
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+92,:));
%     end
% end
% for m = 99:104
%     for n = 1:6
%         difscores(m,n) = dtw(simarray(m,:),simarray(n+104,:));
%     end
% end
posrates = xlsread('Book3.xlsx','A2:E2');

bar(posrates);