%%%%%%%%%%%%%%%%%%%%%%%%%% distribution first user

% discores11d=importdata('discores11.mat');
% discores12d=importdata('discores12.mat');
% % Generates histogram for first user dissimilarity scores
% dself1 = histogram(discores11d,'FaceColor',[0 139/255, 139/255],'BinWidth',0.1,'Normalization','probability');
% hold on 
% histogram(discores12d,'FaceColor',[1 125/255 64/255],'BinWidth',0.1,'Normalization','probability');
% legend('Same beat-PIN','Different beat-PINs',28,'FontName','Times New Roman');
% xlabel('Dissimilarity score','fontsize',28,'FontName','Times New Roman');
% ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%% score user 2

% discores21d=importdata('discores21.mat');
% discores22d=importdata('discores22.mat');
% % Generates histogram for first user dissimilarity scores
% dself1 = histogram(discores21d,'FaceColor',[0 139/255, 139/255],'BinWidth',0.1,'Normalization','probability');
% hold on 
% histogram(discores22d,'FaceColor',[1 125/255 64/255],'BinWidth',0.1,'Normalization','probability');
% legend('Same beat-PIN','Different beat-PINs',28,'FontName','Times New Roman');
% xlabel('Dissimilarity score','fontsize',28,'FontName','Times New Roman');
% ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%% score user 3

% discores31d=importdata('discores31.mat');
% discores32d=importdata('discores32.mat');
% % Generates histogram for first user dissimilarity scores
% dself1 = histogram(discores31d,'FaceColor',[0 139/255, 139/255],'BinWidth',0.1,'Normalization','probability');
% hold on 
% histogram(discores32d,'FaceColor',[1 125/255 64/255],'BinWidth',0.1,'Normalization','probability');
% legend('Same beat-PIN','Different beat-PINs',28,'FontName','Times New Roman');
% xlabel('Dissimilarity score','fontsize',28,'FontName','Times New Roman');
% ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%% distribution of beat-pin length
% clear;
% x=1:1:15;
% ours=[0 0 0 0 0.01 16/32 6/32 3/32 3/32 3/32 1/32 0.5/32 0.5/32 0 0];
% bar([1:1:15],ours,'Facecolor',[0 139/255, 139/255]);
% legend('Beat-PIN',28,'FontName','Times New Roman');
% % xlabel('Beat-PIN length','fontsize',28,'FontName','Times New Roman');
% % ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[0 10 800 200]);
% set(gca,'XLim',[0 15]);

%%%%%%%%%%%%%%%%%%%%%%%%%% distribution of pin length
% clear;
% x=1:1:15;
% PIN= [0 0 0 0.4916 0.0921 0.1778 0.0728 0.1126 0.0295 0.0152 0.0038 0.0025 0.0014 0.0007 0];
% bar([1:1:15],PIN,'Facecolor',[1 125/255 64/255]);
% legend('PIN',28,'FontName','Times New Roman');
% % xlabel('Beat-PIN length','fontsize',28,'FontName','Times New Roman');
% % ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[0 10 800 200]);
% set(gca,'XLim',[0 15]);

%%%%%%%%%%%%%%%%%%%%%%%%%% distribution of pwd length
% clear;
% x=1:1:15;
% pwd=[0 0.001 0.002 0.005 0.01 0.185 0.139 0.29 0.125 0.12 0.03 0.02 0.01 0.005 0];
% bar([1:1:15],pwd,'Facecolor',[154/255 205/255 50/255]);
% legend('Password',28,'FontName','Times New Roman');
% % xlabel('Beat-PIN length','fontsize',28,'FontName','Times New Roman');
% % ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[0 10 800 200]);
% set(gca,'XLim',[0 15]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%% matrix score plot

discores=importdata('score.mat');
imagesc(discores);

set(gca,'ytick',[4 9 14 19 24 29],'yticklabels',{'30','25','20','15','10','5'});
xlabel('User index','fontsize',22,'FontName','Times New Roman');
ylabel('User index','fontsize',22,'FontName','Times New Roman');
set(gca,'fontsize',22,'FontName','Times New Roman');
set(gcf,'position',[0 10 550 500]);





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