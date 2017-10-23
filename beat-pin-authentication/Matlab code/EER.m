%%%%%%%%%%%%%%%%%% EER-random
% far=[0.02 0.035 0.05 0.07 0.09 0.12 0.14 0.15 0.2];
% frr=[0.5 0.27 0.12 0.05 0.03 0.02 0.01 0.005 0.001];
% x=0:0.01:0.15;
% y=x;
% 
% p1=plot(far,frr,'LineWidth',3,'Color',[0 139/255, 139/255]);
% hold on;
% plot(x,y,'--','LineWidth',3,'Color',[1 125/255 64/255]);
% 
% legend([p1],{'Zero-effort attack'},28,'FontName','Times New Roman');
% xlabel('FAR','fontsize',28,'FontName','Times New Roman');
% ylabel('FRR','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% grid on;

%%%%%%%%%%%%%%%%%% EER-random
% far=[0.035 0.05 0.07 0.09 0.12 0.14 0.15 0.2];
% frr=[0.27+0.35 0.12+0.20 0.05+0.15 0.03+0.08 0.02+0.03 0.01+0.03 0.005+0.03 0.031];
% x=0:0.01:0.15;
% y=x;
% 
% p1=plot(far,frr,'LineWidth',3,'Color',[0 139/255, 139/255]);
% hold on;
% plot(x,y,'--','LineWidth',3,'Color',[1 125/255 64/255]);
% 
% legend([p1],{'Shoulder surfing attack'},28,'FontName','Times New Roman');
% xlabel('FAR','fontsize',28,'FontName','Times New Roman');
% ylabel('FRR','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'XLim',[0.0 0.2]);
% set(gca,'YLim',[0.0 0.6]);
% 
% set(gcf,'position',[100 10 800 450]);
% grid on;

%%%%%%%%%%%%%%%%%% EER-random
% far=[0.035 0.04 0.05 0.07 0.09 0.1 0.12 0.14 0.15 0.2];
% frr=[0.27+0.25 0.4 0.12+0.15 0.05+0.1 0.03+0.06 0.065 0.02+0.02 0.01+0.02 0.005+0.02 0.021];
% x=0:0.01:0.15;
% y=x;
% 
% p1=plot(far,frr,'LineWidth',3,'Color',[0 139/255, 139/255]);
% hold on;
% plot(x,y,'--','LineWidth',3,'Color',[1 125/255 64/255]);
% 
% legend([p1],{'Statistic attack'},28,'FontName','Times New Roman');
% xlabel('FAR','fontsize',28,'FontName','Times New Roman');
% ylabel('FRR','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'XLim',[0.0 0.2]);
% set(gca,'YLim',[0.0 0.5]);
% 
% 
% set(gcf,'position',[100 10 800 450]);
% grid on;

% %%%%%%%%%%%%%%%%%%% distance bar
% 
% %x = categorical({'1','2','4','5','10'});
% x=1:1:5;
% far=[0.335 0.114 0.078 0.071 0.071];
% bar(x,far,'FaceColor',[0 139/255, 139/255]);
% 
% xlabel('Distance (m)','fontsize',28,'FontName','Times New Roman');
% ylabel('FAR','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'xticklabels',{'1','2','4','5','10'});

%%%%%%%%%%%%%%%%%%% pin length

% x=6:1:10;
% far=[0.228 0.175 0.088 0.081 0.073];
% bar(x,far,'FaceColor',[0 139/255, 139/255]);
% 
% xlabel('Beat-PIN length','fontsize',28,'FontName','Times New Roman');
% ylabel('FAR','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'XLim',[5 11]);

% %%%%%%%%%%%%%%%%%%% pin frequency
% 
% x=1:1:20;
% frequency=0.01.*[10.713 6.016 1.881 1.197 0.745 0.616 0.613 0.526 0.516 0.512 0.451 0.419 0.395 0.391 0.366 0.304 0.303 0.293 0.29 0.285];
% bar(x,frequency,'FaceColor',[0 139/255, 139/255]);
% 
% xlabel('Index','fontsize',24,'FontName','Times New Roman');
% ylabel('Frequency','fontsize',24,'FontName','Times New Roman');
% set(gca,'fontsize',24,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 400]);
% set(gca,'XLim',[0 21]);
% legend('PIN',24,'FontName','Times New Roman');
% %set(gca,'xticklabels',{'1','2','4','5','10'});

% %%%%%%%%%%%%%%%%%%% beatpin frequency
% 
% x=1:1:20;
% frequency=(1/44).*[3 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1];
% bar(x,frequency,'FaceColor',[1 125/255 64/255]);
% 
% xlabel('Index','fontsize',24,'FontName','Times New Roman');
% ylabel('Frequency','fontsize',24,'FontName','Times New Roman');
% set(gca,'fontsize',24,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 400]);
% set(gca,'XLim',[0 21]);
% set(gca,'YLim',[0 0.12]);
% legend('Beat-PIN',24,'FontName','Times New Roman');
% %set(gca,'xticklabels',{'1','2','4','5','10'});

% %%%%%%%%%%%%%%%%%%% remember
% 
% x=1:1:4;
% frequency=[2.92 2.89 2.68 2.98];
% bar(x,frequency,0.5,'FaceColor',[0 139/255, 139/255]);
% 
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'YLim',[2.5 3]);
% set(gca,'xticklabels',{'Beat-PIN','PIN','Pattern','Finger.'});
% title('Easy for memorization?');

% %%%%%%%%%%%%%%%%%%% remember
% 
% x=1:1:4;
% frequency=[2.58 2.52 2.31 2.65];
% bar(x,frequency,0.5,'FaceColor',[0 139/255, 139/255]);
% 
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'YLim',[2.1 2.8]);
% set(gca,'xticklabels',{'Beat-PIN','PIN','Pattern','Finger.'});
% title('Fast to login?');

% %%%%%%%%%%%%%%%%%%% remember
% 
% x=1:1:4;
% frequency=[2.68 2.69 2.40 2.78];
% bar(x,frequency,0.5,'FaceColor',[0 139/255, 139/255]);
% 
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'YLim',[2.2 2.9]);
% set(gca,'xticklabels',{'Beat-PIN','PIN','Pattern','Finger.'});
% title('Convinient to perform?');

%%%%%%%%%%%%%%%%%%% remember

% x=1:1:4;
% frequency=[2.4 2.6 2.1 2.5];
% bar(x,frequency,0.5,'FaceColor',[0 139/255, 139/255]);
% 
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gca,'YLim',[2.0 2.7]);
% set(gca,'xticklabels',{'Beat-PIN','PIN','Pattern','Finger.'});
% title('Less error prone?');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
L_max=4;
T_max=10.8;
tau_s=0.12;
tau_b=0.08;
sigma=1/1.8*10^(-6);
NTmax=floor(T_max/sigma);
Ns=floor(tau_s/sigma);
Nb=floor(tau_b/sigma);

aa=0;

for l=1:L_max
    upper=NTmax-(Nb-1)*l-(Ns-1)*(l-1)
    lower=2*l-1;
    temp=factorial(upper)/(factorial(upper-lower)*factorial(lower));
    aa=aa+temp;
    temp=0;
end

    
    
    
    
    