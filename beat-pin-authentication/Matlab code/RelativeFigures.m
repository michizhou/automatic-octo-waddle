relatives1 = zeros(15,25);
relatives2 = zeros(15,4);

% Imports data about beat intervals between timestamps from Excel file for first user
relatives1(1,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB18:AZ18');
relatives1(2,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB19:AZ19');
relatives1(3,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB20:AZ20');
relatives1(4,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB21:AZ21');
relatives1(5,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB22:AZ22');
relatives1(6,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB23:AZ23');
relatives1(7,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB24:AZ24');
relatives1(8,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB25:AZ25');
relatives1(9,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB26:AZ26');
relatives1(10,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB27:AZ27');
relatives1(11,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB28:AZ28');
relatives1(12,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB29:AZ29');
relatives1(13,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB30:AZ30');
relatives1(14,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB31:AZ31');
relatives1(15,1:25) = xlsread('Processed Data.xlsx','TapIntervals','AB32:AZ32');

% Imports data about beat intervals between timestamps from Excel file for second user 
relatives2(1,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P35:S35');
relatives2(2,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P36:S36');
relatives2(3,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P37:S37');
relatives2(4,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P38:S38');
relatives2(5,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P39:S39');
relatives2(6,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P40:S40');
relatives2(7,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P41:S41');
relatives2(8,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P42:S42');
relatives2(9,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P43:S43');
relatives2(10,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P44:S44');
relatives2(11,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P45:S45');
relatives2(12,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P46:S46');
relatives2(13,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P47:S47');
relatives2(14,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P48:S48');
relatives2(15,1:4) = xlsread('Processed Data.xlsx','TapIntervals','P49:S49');

% Creates histograms of tapping beat frequencies 
t1graph = histogram(relatives1,25,'Normalization','probability');
t2graph = histogram(relatives2,25,'Normalization','probability');

% Creates histogram line plot (two random users) of tapping beat frequencies
x1 = xlsread('Processed Data.xlsx','Distribution Plots','Z1:Z20');
y1 = xlsread('Processed Data.xlsx','Distribution Plots','AA1:AA20');

x2 = xlsread('Processed Data.xlsx','Distribution Plots','AC1:AC11');
y2 = xlsread('Processed Data.xlsx','Distribution Plots','AD1:AD11');

plot(x1,y1,x2,y2,'--');
legend('User1','User2');

% Creates line plot for password frequencies by length 
x3 = xlsread('Processed Data.xlsx','NormalData','A562:G562');
y3 = xlsread('Processed Data.xlsx','NormalData','A563:G563');

plot(x3,y3);