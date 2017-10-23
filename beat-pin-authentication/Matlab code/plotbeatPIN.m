%%%%%%%%%%%%%%%%%%%%%%%%%% total pin length
% x=importdata('pinlengthdistx.mat');
% y=importdata('pinlengthdisty.mat');
% 
% plot(x,y,'LineWidth',3,'Color',[0 139/255, 139/255]);
% 
% legend('BeatPIN total length',28,'FontName','Times New Roman');
% xlabel('Time (s)','fontsize',28,'FontName','Times New Roman');
% ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%% tau_s
x=importdata('tausx.mat');
y=importdata('tausy.mat');
x=2.*x;
plot(x,y,'LineWidth',3,'Color',[0 139/255, 139/255]);

legend('\tau_s',28,'FontName','Times New Roman');
xlabel('Time (s)','fontsize',28,'FontName','Times New Roman');
ylabel('Probability','fontsize',28,'FontName','Times New Roman');
set(gca,'fontsize',28,'FontName','Times New Roman');
set(gcf,'position',[100 10 800 450]);
set(gca,'XLim',[0 3]);
grid on;

% %%%%%%%%%%%%%%%%%%%%%%%%%% tau_b
% x=importdata('taubx.mat');
% x=10.*x;
% x(1)=2*x(1);
% y=importdata('tauby.mat');
% y=2.*y;
% 
% plot(x,y,'LineWidth',3,'Color',[0 139/255, 139/255]);
% 
% legend('\tau_b',28,'FontName','Times New Roman');
% xlabel('Time (s)','fontsize',28,'FontName','Times New Roman');
% ylabel('Probability','fontsize',28,'FontName','Times New Roman');
% set(gca,'fontsize',28,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 450]);
% set(gca,'XLim',[0 3]);
% grid on;