%%%%%%%%%%%%%%%%%%%%%%% kernel bar fpr

% fnr=[0.045 0.081 0.090;
%      0.037 0.072 0.081;
%      0.050 0.089 0.093];
% fpr=[0.08 0.084 0.083;
%      0.075 0.072 0.076;
%      0.088 0.092 0.091];
% a=boxplot(fpr,'colors',[0 139/255, 139/255],'width',0.3);
% set(a,{'linew'},{3});
% hold on;
% b=boxplot(fnr,'colors',[1 125/255 64/255],'width',0.3);
% set(b,{'linew'},{3});
% 
% 
% %xlabel('\nu','fontsize',22,'FontName','Times New Roman');
% ylabel('FAR/FRR','fontsize',20,'FontName','Times New Roman');
% set(gca,'fontsize',20,'FontName','Times New Roman');
% %set(gcf,'position',[0 10 800 400]);
% %set(gca,'XLim',[0 0.2]);
% set(gca,'YLim',[0 0.1]);
% %set(gca,'xticklabel',[]);
% set(gca,'xticklabels',{'Sitting', 'Slow walk', 'Fast walk'});
% 
% grid on;


%hLegend = legend(findall(gca,'Tag','Box'), {'Group A','Group B'});

% boxes = findobj(gca, 'Tag', 'Box');
% legend(boxes([end 1]), 'FAR', 'FRR','fontsize',28);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fnr=[0.059 0.061 0.051 0.080 0.053;
     0.052 0.058 0.047 0.075 0.050;
     0.063 0.066 0.057 0.086 0.059];


fpr=[0.095 0.020 0.084 0.01 0.052;
     0.090 0.017 0.080 0 0.047;
     0.11  0.022 0.088 0.013 0.058];

a=boxplot(fpr,'colors',[0 139/255, 139/255],'width',0.3);
set(a,{'linew'},{3});
hold on;
b=boxplot(fnr,'colors',[1 125/255 64/255],'width',0.3);
set(b,{'linew'},{3});


%xlabel('\nu','fontsize',22,'FontName','Times New Roman');
ylabel('FAR/FRR','fontsize',20,'FontName','Times New Roman');
set(gca,'fontsize',20,'FontName','Times New Roman');
%set(gcf,'position',[0 10 800 400]);
%set(gca,'XLim',[0 0.2]);
set(gca,'YLim',[0 0.12]);
%set(gca,'xticklabel',[]);
set(gca,'xticklabels',{'LGL15G', 'Moto G', 'Nexus 4', 'Nexus 5x', 'Huawei H.'});

grid on;

boxes = findobj(gca, 'Tag', 'Box');
legend(boxes([end 1]), 'FAR', 'FRR','fontsize',28);

