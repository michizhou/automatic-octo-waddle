% intervals3 = zeros(15,26); % Figure 4
% intervals4 = zeros(15,5); % Figure 4
passuser1 = zeros(15,12); % Figure 3
passuser2 = zeros(15,9); % Figure 3
% 
% % Imports data about beat intervals between timestamps from Excel file for first user (Figure 4)
% intervals3(1,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A18:Z18');
% intervals3(2,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A19:Z19');
% intervals3(3,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A20:Z20');
% intervals3(4,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A21:Z21');
% intervals3(5,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A22:Z22');
% intervals3(6,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A23:Z23');
% intervals3(7,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A24:Z24');
% intervals3(8,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A25:Z25');
% intervals3(9,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A26:Z26');
% intervals3(10,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A27:Z27');
% intervals3(11,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A28:Z28');
% intervals3(12,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A29:Z29');
% intervals3(13,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A30:Z30');
% intervals3(14,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A31:Z31');
% intervals3(15,1:26) = xlsread('Processed Data.xlsx','TapIntervals','A32:Z32');
% 
% % Imports data about beat intervals between timestamps from Excel file for second user (Figure 4)
% intervals4(1,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I35:M35');
% intervals4(2,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I36:M36');
% intervals4(3,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I37:M37');
% intervals4(4,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I38:M38');
% intervals4(5,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I39:M39');
% intervals4(6,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I40:M40');
% intervals4(7,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I41:M41');
% intervals4(8,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I42:M42');
% intervals4(9,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I43:M43');
% intervals4(10,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I44:M44');
% intervals4(11,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I45:M45');
% intervals4(12,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I46:M46');
% intervals4(13,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I47:M47');
% intervals4(14,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I48:M48');
% intervals4(15,1:5) = xlsread('Processed Data.xlsx','TapIntervals','I49:M49');
% 
% Imports data for second user's unnormalized setup password sequences from Excel file (Figure 3)
passuser1(1,1:12) = xlsread('Processed Data.xlsx','NormalData','AE162:AP162');
passuser1(2,1:12) = xlsread('Processed Data.xlsx','NormalData','AE163:AP163');
passuser1(3,1:12) = xlsread('Processed Data.xlsx','NormalData','AE164:AP164');
passuser1(4,1:12) = xlsread('Processed Data.xlsx','NormalData','AE165:AP165');
passuser1(5,1:12) = xlsread('Processed Data.xlsx','NormalData','AE166:AP166');
passuser1(6,1:12) = xlsread('Processed Data.xlsx','NormalData','AE167:AP167');
passuser1(7,1:12) = xlsread('Processed Data.xlsx','NormalData','AE168:AP168');
passuser1(8,1:12) = xlsread('Processed Data.xlsx','NormalData','AE169:AP169');
passuser1(9,1:12) = xlsread('Processed Data.xlsx','NormalData','AE170:AP170');
passuser1(10,1:12) = xlsread('Processed Data.xlsx','NormalData','AE171:AP171');
passuser1(11,1:12) = xlsread('Processed Data.xlsx','NormalData','AE172:AP172');
passuser1(12,1:12) = xlsread('Processed Data.xlsx','NormalData','AE173:AP173');
passuser1(13,1:12) = xlsread('Processed Data.xlsx','NormalData','AE174:AP174');
passuser1(14,1:12) = xlsread('Processed Data.xlsx','NormalData','AE175:AP175');
passuser1(15,1:12) = xlsread('Processed Data.xlsx','NormalData','AE176:AP176');

% Imports data for fourth user's unnormalized setup password sequences from Excel file (Figure 3)
passuser2(1,1:9) = xlsread('Processed Data.xlsx','NormalData','Y332:AG332');
passuser2(2,1:9) = xlsread('Processed Data.xlsx','NormalData','Y333:AG333');
passuser2(3,1:9) = xlsread('Processed Data.xlsx','NormalData','Y334:AG334');
passuser2(4,1:9) = xlsread('Processed Data.xlsx','NormalData','Y335:AG335');
passuser2(5,1:9) = xlsread('Processed Data.xlsx','NormalData','Y336:AG336');
passuser2(6,1:9) = xlsread('Processed Data.xlsx','NormalData','Y337:AG337');
passuser2(7,1:9) = xlsread('Processed Data.xlsx','NormalData','Y338:AG338');
passuser2(8,1:9) = xlsread('Processed Data.xlsx','NormalData','Y339:AG339');
passuser2(9,1:9) = xlsread('Processed Data.xlsx','NormalData','Y340:AG340');
passuser2(10,1:9) = xlsread('Processed Data.xlsx','NormalData','Y341:AG341');
passuser2(11,1:9) = xlsread('Processed Data.xlsx','NormalData','Y342:AG342');
passuser2(12,1:9) = xlsread('Processed Data.xlsx','NormalData','Y343:AG343');
passuser2(13,1:9) = xlsread('Processed Data.xlsx','NormalData','Y344:AG344');
passuser2(14,1:9) = xlsread('Processed Data.xlsx','NormalData','Y345:AG345');
passuser2(15,1:9) = xlsread('Processed Data.xlsx','NormalData','Y346:AG346');
% 
% Creates histograms of tapping beat frequencies (Figure 3)
% t1graph = histogram(passuser1,25,'Normalization','probability');
% t2graph = histogram(passuser2,25,'Normalization','probability');
% 
% % Create histograms of beat interval frequencies (Figure 4)
% int1graph = histogram(intervals3,25,'Normalization','probability');
% int2graph = histogram(intervals4,25,'Normalization','probability');
% 
% % Creates histogram line plot (two random users) of tapping beat frequencies (Figure 3)
% x1 = xlsread('Processed Data.xlsx','Distribution Plots','N1:N20');
% y1 = xlsread('Processed Data.xlsx','Distribution Plots','O1:O20');
% 
% x2 = xlsread('Processed Data.xlsx','Distribution Plots','Q1:Q18');
% y2 = xlsread('Processed Data.xlsx','Distribution Plots','R1:R18');
% 
% plot(x1,y1,x2,y2,'--');
% legend('User1','User2');
% 
% % Creates histogram line plot (two random users) of beat interval frequencies (Figure 4)
x3 = xlsread('Processed Data.xlsx','Distribution Plots','G1:G17');
y3 = xlsread('Processed Data.xlsx','Distribution Plots','H1:H17');

x4 = xlsread('Processed Data.xlsx','Distribution Plots','J1:J16');
y4 = xlsread('Processed Data.xlsx','Distribution Plots','K1:K16');

plot(x3,y3,x4,y4,'--');
legend('User1','User2');
% 
% Creates histogram line plot (unnormalized time) of tapping beat frequencies (Figure 3)
% x5 = xlsread('Processed Data.xlsx','Distribution Plots','T1:T22');
% y5 = xlsread('Processed Data.xlsx','Distribution Plots','U1:U22');
% 
% x6 = xlsread('Processed Data.xlsx','Distribution Plots','W1:W24');
% y6 = xlsread('Processed Data.xlsx','Distribution Plots','X1:X24');
% 
% plot(x5,y5,x6,y6,'--');
% legend('User1','User2');