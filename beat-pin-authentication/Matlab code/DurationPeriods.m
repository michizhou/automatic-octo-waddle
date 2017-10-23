% durations = zeros(35,15);
durations0 = zeros(1035,1); % Figure 11a
tauup = importdata('TauS Data.xlsx'); % Figure 11b
taudown = importdata('TauB Data.xlsx'); % Figure 11c

% Imports data for time durations of all password attempts (Figure 11a)
durations0(1:1006,1) = xlsread('Processed Data.xlsx','SetupData','AD2:AD1007');
durations0(1007:1035,1) = xlsread('Processed Data.xlsx','SetupData','BH1008:BH1036');

% durations(1,1:15) = xlsread('Processed Data.xlsx','Action Durations','A3:A17');
% durations(2,1:15) = xlsread('Processed Data.xlsx','Action Durations','B3:B17');
% durations(3,1:15) = xlsread('Processed Data.xlsx','Action Durations','C3:C17');
% durations(4,1:15) = xlsread('Processed Data.xlsx','Action Durations','D3:D17');
% durations(5,1:15) = xlsread('Processed Data.xlsx','Action Durations','E3:E17');
% durations(6,1:15) = xlsread('Processed Data.xlsx','Action Durations','F3:F17');
% durations(7,1:15) = xlsread('Processed Data.xlsx','Action Durations','G3:G17');
% durations(8,1:15) = xlsread('Processed Data.xlsx','Action Durations','H3:H17');
% durations(9,1:15) = xlsread('Processed Data.xlsx','Action Durations','I3:I17');
% durations(10,1:15) = xlsread('Processed Data.xlsx','Action Durations','J3:J17');
% durations(11,1:15) = xlsread('Processed Data.xlsx','Action Durations','K3:K17');
% durations(12,1:15) = xlsread('Processed Data.xlsx','Action Durations','L3:L17');
% durations(13,1:15) = xlsread('Processed Data.xlsx','Action Durations','M3:M17');
% durations(14,1:15) = xlsread('Processed Data.xlsx','Action Durations','N3:N17');
% durations(15,1:15) = xlsread('Processed Data.xlsx','Action Durations','O3:O17');
% durations(16,1:15) = xlsread('Processed Data.xlsx','Action Durations','P3:P17');
% durations(17,1:15) = xlsread('Processed Data.xlsx','Action Durations','Q3:Q17');
% durations(18,1:15) = xlsread('Processed Data.xlsx','Action Durations','R3:R17');
% durations(19,1:15) = xlsread('Processed Data.xlsx','Action Durations','S3:S17');
% durations(20,1:15) = xlsread('Processed Data.xlsx','Action Durations','T3:T17');
% durations(21,1:15) = xlsread('Processed Data.xlsx','Action Durations','U3:U17');
% durations(22,1:15) = xlsread('Processed Data.xlsx','Action Durations','V3:V17');
% durations(23,1:15) = xlsread('Processed Data.xlsx','Action Durations','W3:W17');
% durations(24,1:15) = xlsread('Processed Data.xlsx','Action Durations','X3:X17');
% durations(25,1:15) = xlsread('Processed Data.xlsx','Action Durations','Y3:Y17');
% durations(26,1:15) = xlsread('Processed Data.xlsx','Action Durations','Z3:Z17');
% durations(27,1:15) = xlsread('Processed Data.xlsx','Action Durations','AA3:AA17');
% durations(28,1:15) = xlsread('Processed Data.xlsx','Action Durations','AB3:AB17');
% durations(29,1:15) = xlsread('Processed Data.xlsx','Action Durations','AC3:AC17');
% durations(30,1:15) = xlsread('Processed Data.xlsx','Action Durations','AD3:AD17');
% durations(31,1:15) = xlsread('Processed Data.xlsx','Action Durations','AE3:AE17');
% durations(32,1:15) = xlsread('Processed Data.xlsx','Action Durations','AF3:AF17');
% durations(33,1:15) = xlsread('Processed Data.xlsx','Action Durations','AG3:AG17');
% durations(34,1:15) = xlsread('Processed Data.xlsx','Action Durations','AA18:AA32');
% durations(35,1:5) = xlsread('Processed Data.xlsx','Action Durations','P18:P22');
% durations(35,6:10) = xlsread('Processed Data.xlsx','Action Durations','X18:X22');
% durations(35,11:12) = xlsread('Processed Data.xlsx','Action Durations','L18:L19');
% durations(35,13:14) = xlsread('Processed Data.xlsx','Action Durations','V18:V19');
% durations(35,15) = xlsread('Processed Data.xlsx','Action Durations','S18');

% histogram(durations0,50,'Normalization','probability');
% histogram(durations0,50,'Normalization','pdf');

% % Creates histogram line plots for frequencies and pdf of time durations (Figure 11a)
% x1 = xlsread('Processed Data.xlsx','Action Durations','A25:A60');
% y1 = xlsread('Processed Data.xlsx','Action Durations','B25:B60');
% 
% x2 = xlsread('Processed Data.xlsx','Action Durations','D25:D60');
% y2 = xlsread('Processed Data.xlsx','Action Durations','E25:E60');
% 
% durationplot1 = plot(x1,y1); % Frequencies plot
% durationplot2 = plot(x2,y2); % Pdf plot
% 
% % histogram(tauup,100,'Normalization','probability');
% % histogram(tauup,100,'Normalization','pdf');

% % Creates histogram line plots for frequencies and pdf of action-up tauS intervals (Figure 11b)
% x3 = xlsread('Processed Data.xlsx','Action Durations','G25:G44');
% y3 = xlsread('Processed Data.xlsx','Action Durations','H25:H44');
% 
% x4 = xlsread('Processed Data.xlsx','Action Durations','J25:J44');
% y4 = xlsread('Processed Data.xlsx','Action Durations','K25:K44');
% 
% tauSplot1 = plot(x3,y3); % Frequencies plot
% tauSplot2 = plot(x4,y4); % Pdf plot

% histogram(taudown,100,'Normalization','probability');
% histogram(taudown,100,'Normalization','pdf');

% Creates histogram line plots for frequencies and pdf of action-down tauB intervals (Figure 11c)
x5 = xlsread('Processed Data.xlsx','Action Durations','M25:M88');
y5 = xlsread('Processed Data.xlsx','Action Durations','N25:N88');

x6 = xlsread('Processed Data.xlsx','Action Durations','P25:P88');
y6 = xlsread('Processed Data.xlsx','Action Durations','Q25:Q88');

tauBplot1 = plot(x5,y5); % Frequencies plot
%tauBplot2 = plot(x6,y6); % Pdf plot
