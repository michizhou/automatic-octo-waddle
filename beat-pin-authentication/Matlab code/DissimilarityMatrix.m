rows = zeros(32,12); % Figure 1
dissim = ones(33,33); % Figures 1 and 2

user1 = ones(15,27); %33 (User Number) (Figure 2)
user2 = ones(15,12); %11 (User Number) (Figures 2 and 3)
user3 = ones(18,10); %12 (User Number) (Figure 2)
user4 = ones(15,9);  %21 (User Number) (Figures 2 and 3)

discores11 = zeros(15,15); % Figure 2
discores21 = zeros(15,15); % Figure 2
discores31 = zeros(18,18); % Figure 2
discores41 = zeros(15,15); % Figure 2

discores12 = zeros(28,8); % Figure 2
discores22 = zeros(28,8); % Figure 2
discores32 = zeros(28,8); % Figure 2
discores42 = zeros(28,8); % Figure 2

% Imports normalized password timestamp sequences from Excel file (Figure 1)
rows(1,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C1:H1');
rows(2,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C2:I2');
rows(3,1:8) = xlsread('Processed Data.xlsx','Password Sequences','C3:J3');
rows(4,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C4:H4');
rows(5,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C5:H5');
rows(6,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C6:I6');
rows(7,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C7:I7');
rows(8,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C8:H8');
rows(9,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C9:H9');
rows(10,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C10:H10');
rows(11,1:12) = xlsread('Processed Data.xlsx','Password Sequences','C11:N11');
rows(12,1:10) = xlsread('Processed Data.xlsx','Password Sequences','C12:L12');
rows(13,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C13:H13');
rows(14,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C14:H14');
rows(15,1:9) = xlsread('Processed Data.xlsx','Password Sequences','C15:K15');
rows(16,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C16:I16');
rows(17,1:9) = xlsread('Processed Data.xlsx','Password Sequences','C17:K17');
rows(18,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C18:H18');
rows(19,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C19:H19');
rows(20,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C20:I20');
rows(21,1:9) = xlsread('Processed Data.xlsx','Password Sequences','C21:K21');
rows(22,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C22:H22');
rows(23,1:10) = xlsread('Processed Data.xlsx','Password Sequences','C23:L23');
rows(24,1:8) = xlsread('Processed Data.xlsx','Password Sequences','C24:J24');
rows(25,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C25:H25');
rows(26,1:8) = xlsread('Processed Data.xlsx','Password Sequences','C26:J26');
rows(27,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C27:H27');
rows(28,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C28:H28');
rows(29,1:10) = xlsread('Processed Data.xlsx','Password Sequences','C29:L29');
rows(30,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C30:H30');
rows(31,1:7) = xlsread('Processed Data.xlsx','Password Sequences','C31:I31');
rows(32,1:6) = xlsread('Processed Data.xlsx','Password Sequences','C32:H32');
oddrow = xlsread('Processed Data.xlsx','Password Sequences','C33:AC33');

% Imports data for first user's setup password sequences from Excel file (Figure 2)
user1(1,1:27) = xlsread('Processed Data.xlsx','NormalData','AF546:BF546'); 
user1(2,1:27) = xlsread('Processed Data.xlsx','NormalData','AF547:BF547');
user1(3,1:27) = xlsread('Processed Data.xlsx','NormalData','AF548:BF548');
user1(4,1:27) = xlsread('Processed Data.xlsx','NormalData','AF549:BF549');
user1(5,1:27) = xlsread('Processed Data.xlsx','NormalData','AF550:BF550');
user1(6,1:27) = xlsread('Processed Data.xlsx','NormalData','AF551:BF551');
user1(7,1:27) = xlsread('Processed Data.xlsx','NormalData','AF552:BF552');
user1(8,1:27) = xlsread('Processed Data.xlsx','NormalData','AF553:BF553');
user1(9,1:27) = xlsread('Processed Data.xlsx','NormalData','AF554:BF554');
user1(10,1:27) = xlsread('Processed Data.xlsx','NormalData','AF555:BF555');
user1(11,1:27) = xlsread('Processed Data.xlsx','NormalData','AF556:BF556');
user1(12,1:27) = xlsread('Processed Data.xlsx','NormalData','AF557:BF557');
user1(13,1:27) = xlsread('Processed Data.xlsx','NormalData','AF558:BF558');
user1(14,1:27) = xlsread('Processed Data.xlsx','NormalData','AF559:BF559');
user1(15,1:27) = xlsread('Processed Data.xlsx','NormalData','AF560:BF560');

% Imports data for second user's setup password sequences from Excel file (Figure 2)
user2(1,1:12) = xlsread('Processed Data.xlsx','NormalData','Q162:AB162');
user2(2,1:12) = xlsread('Processed Data.xlsx','NormalData','Q163:AB163');
user2(3,1:12) = xlsread('Processed Data.xlsx','NormalData','Q164:AB164');
user2(4,1:12) = xlsread('Processed Data.xlsx','NormalData','Q165:AB165');
user2(5,1:12) = xlsread('Processed Data.xlsx','NormalData','Q166:AB166');
user2(6,1:12) = xlsread('Processed Data.xlsx','NormalData','Q167:AB167');
user2(7,1:12) = xlsread('Processed Data.xlsx','NormalData','Q168:AB168');
user2(8,1:12) = xlsread('Processed Data.xlsx','NormalData','Q169:AB169');
user2(9,1:12) = xlsread('Processed Data.xlsx','NormalData','Q170:AB170');
user2(10,1:12) = xlsread('Processed Data.xlsx','NormalData','Q171:AB171');
user2(11,1:12) = xlsread('Processed Data.xlsx','NormalData','Q172:AB172');
user2(12,1:12) = xlsread('Processed Data.xlsx','NormalData','Q173:AB173');
user2(13,1:12) = xlsread('Processed Data.xlsx','NormalData','Q174:AB174');
user2(14,1:12) = xlsread('Processed Data.xlsx','NormalData','Q175:AB175');
user2(15,1:12) = xlsread('Processed Data.xlsx','NormalData','Q176:AB176');

% Imports data for third user's setup password sequences from Excel file (Figure 2)
user3(1,1:10) = xlsread('Processed Data.xlsx','NormalData','O178:X178');
user3(2,1:10) = xlsread('Processed Data.xlsx','NormalData','O179:X179');
user3(3,1:10) = xlsread('Processed Data.xlsx','NormalData','O180:X180');
user3(4,1:10) = xlsread('Processed Data.xlsx','NormalData','O181:X181');
user3(5,1:10) = xlsread('Processed Data.xlsx','NormalData','O182:X182');
user3(6,1:10) = xlsread('Processed Data.xlsx','NormalData','O183:X183');
user3(7,1:10) = xlsread('Processed Data.xlsx','NormalData','O184:X184');
user3(8,1:10) = xlsread('Processed Data.xlsx','NormalData','O185:X185');
user3(9,1:10) = xlsread('Processed Data.xlsx','NormalData','O186:X186');
user3(10,1:10) = xlsread('Processed Data.xlsx','NormalData','O187:X187');
user3(11,1:10) = xlsread('Processed Data.xlsx','NormalData','O188:X188');
user3(12,1:10) = xlsread('Processed Data.xlsx','NormalData','O189:X189');
user3(13,1:10) = xlsread('Processed Data.xlsx','NormalData','O190:X190');
user3(14,1:10) = xlsread('Processed Data.xlsx','NormalData','O191:X191');
user3(15,1:10) = xlsread('Processed Data.xlsx','NormalData','O192:X192');
user3(16,1:10) = xlsread('Processed Data.xlsx','NormalData','O193:X193');
user3(17,1:10) = xlsread('Processed Data.xlsx','NormalData','O194:X194');
user3(18,1:10) = xlsread('Processed Data.xlsx','NormalData','O195:X195');

% Imports data for fourth user's setup password sequences from Excel file (Figure 2)
user4(1,1:9) = xlsread('Processed Data.xlsx','NormalData','N332:V332');
user4(2,1:9) = xlsread('Processed Data.xlsx','NormalData','N333:V333');
user4(3,1:9) = xlsread('Processed Data.xlsx','NormalData','N334:V334');
user4(4,1:9) = xlsread('Processed Data.xlsx','NormalData','N335:V335');
user4(5,1:9) = xlsread('Processed Data.xlsx','NormalData','N336:V336');
user4(6,1:9) = xlsread('Processed Data.xlsx','NormalData','N337:V337');
user4(7,1:9) = xlsread('Processed Data.xlsx','NormalData','N338:V338');
user4(8,1:9) = xlsread('Processed Data.xlsx','NormalData','N339:V339');
user4(9,1:9) = xlsread('Processed Data.xlsx','NormalData','N340:V340');
user4(10,1:9) = xlsread('Processed Data.xlsx','NormalData','N341:V341');
user4(11,1:9) = xlsread('Processed Data.xlsx','NormalData','N342:V342');
user4(12,1:9) = xlsread('Processed Data.xlsx','NormalData','N343:V343');
user4(13,1:9) = xlsread('Processed Data.xlsx','NormalData','N344:V344');
user4(14,1:9) = xlsread('Processed Data.xlsx','NormalData','N345:V345');
user4(15,1:9) = xlsread('Processed Data.xlsx','NormalData','N346:V346');

% Creates dissimilarity square to make shading closer through scaling (Figure 1)
for m = 1:32
    for n = 1:32
        if m == 11  
            dissim(34-m,n) = dtw(rows(m,:),rows(n,:));
        elseif n == 11
            dissim(34-m,n) = dtw(rows(m,:),rows(n,:)); 
        else
            dissim(34-m,n) = dtw(rows(m,:),rows(n,:)) * 7.5;
        end
    end
end

for i = 1:32
    dissim(1,i) = dtw(rows(i,:),oddrow);
    dissim(34-i,33) = dtw(rows(i,:),oddrow);
end
dissim(1,33) = 0;

% Generates dissimilarity scores (self and different) for user passwords (Figure 2)
for m = 1:15
    for n = 1:15
        discores11(m,n) = dtw(user1(m,:),user1(n,:)); %33
        discores21(m,n) = dtw(user2(m,:),user2(n,:)); %11
        discores41(m,n) = dtw(user4(m,:),user4(n,:)); %21
    end
end
for m = 1:18
    for n = 1:18
        discores31(m,n) = dtw(user3(m,:),user3(n,:)); %12
    end
end

for i = 1:7
    for m = 1:4
        for n = 1:8
            discores12(4*(i-1) + m,n) = dissim(1,8*(m-1) + n);
            if 8*(m-1) + n < 11
                discores22(4*(i-1) + m,n) = dissim(23,8*(m-1) + n);
                discores32(4*(i-1) + m,n) = dissim(22,8*(m-1) + n);
                discores42(4*(i-1) + m,n) = dissim(13,8*(m-1) + n);
            elseif 8*(m-1) + n < 12
                discores22(4*(i-1) + m,n) = dissim(23,8*(m-1) + n+1);
                discores32(4*(i-1) + m,n) = dissim(22,8*(m-1) + n);
                discores42(4*(i-1) + m,n) = dissim(13,8*(m-1) + n);
            elseif 8*(m-1) + n < 21
                discores22(4*(i-1) + m,n) = dissim(23,8*(m-1) + n+1);
                discores32(4*(i-1) + m,n) = dissim(22,8*(m-1) + n+1);
                discores42(4*(i-1) + m,n) = dissim(13,8*(m-1) + n);
            else
                discores22(4*(i-1) + m,n) = dissim(23,8*(m-1) + n+1);
                discores32(4*(i-1) + m,n) = dissim(22,8*(m-1) + n+1);
                discores42(4*(i-1) + m,n) = dissim(13,8*(m-1) + n+1);
            end
        end
    end
end

% Creates histograms (four different users) with same and different pins (Figure 2)

% Generates histogram for first user dissimilarity scores
dself1 = histogram(discores11,'FaceColor','g','BinWidth',0.1,'Normalization','probability');
hold on 
histogram(discores12,'FaceColor','y','BinWidth',0.1,'Normalization','probability');
legend('Same User PINs','Different User PINs');
% 
% % Generates histogram for second user dissimilarity scores
% dself2 = histogram(discores21,'FaceColor','g','BinWidth',0.1,'Normalization','probability');
% hold on
% histogram(discores22,'FaceColor','y','BinWidth',0.1,'Normalization','probability');
% legend('Same User PINs','Different User PINs');
% 
% % Generates histogram for third user dissimilarity scores
% dself3 = histogram(discores31,'FaceColor','g','BinWidth',0.1,'Normalization','probability');
% hold on
% histogram(discores32,'FaceColor','y','BinWidth',0.1,'Normalization','probability');
% legend('Same User PINs','Different User PINs');
% 
% % Generates histogram for fourth user dissimilarity scores
% dself4 = histogram(discores41,'FaceColor','g','BinWidth',0.1,'Normalization','probability');
% hold on
% histogram(discores42,'FaceColor','y','BinWidth',0.1,'Normalization','probability');
% legend('Same User PINs','Different User PINs');

% %Creates histograms (two different users) of tapping beat frequencies (Figure 3)
% tapgraph1 = histogram(user2);
% tapgraph2 = histogram(user4);
