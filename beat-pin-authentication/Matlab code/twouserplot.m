%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% plot of two user's relative interval
% clear;
% x1=[0.170000000000000;0.510000000000000;0.850000000000000;1.19000000000000;1.53000000000000;1.87000000000000;2.21000000000000;2.55000000000000;2.89000000000000;3.23000000000000;3.57000000000000;3.91000000000000;4.25000000000000;5.27000000000000;6.29000000000000;6.63000000000000;6.97000000000000;7.31000000000000;7.65000000000000;8.33000000000000];
% x2=[0.345000000000000;0.635000000000000;0.925000000000000;1.79500000000000;2.08500000000000;2.37500000000000;2.66500000000000;2.95500000000000;3.24500000000000;3.53500000000000;7.30500000000000];
% y1=[0.146700000000000;0.213300000000000;0.133300000000000;0.176000000000000;0.0506700000000000;0.0373300000000000;0.0373300000000000;0.0400000000000000;0.0480000000000000;0.0453300000000000;0.0160000000000000;0.0133300000000000;0.00266700000000000;0.00266700000000000;0.0106700000000000;0.00533300000000000;0.00533300000000000;0.0106700000000000;0.00266700000000000;0.00266700000000000];
% y2=[0.416700000000000;0.0833300000000000;0.0166700000000000;0.0333300000000000;0.0333300000000000;0.100000000000000;0.116700000000000;0.133300000000000;0.0333300000000000;0.0166700000000000;0.0166700000000000];
% 
% plot(x1,y1,'LineWidth',3,'Color',[0 139/255, 139/255]);
% hold on;
% plot(x2,y2,'--','LineWidth',3,'Color',[1 125/255 64/255]);
% 
% legend('User 1','User 2',24,'FontName','Times New Roman');
% xlabel('Relative interval','fontsize',24,'FontName','Times New Roman');
% ylabel('Probability','fontsize',24,'FontName','Times New Roman');
% set(gca,'fontsize',24,'FontName','Times New Roman');
% set(gcf,'position',[100 10 800 400]);
% grid on;


%%%%%%%%%%%%%%%%%%%%%%%%% plot tapping interval
x3=[0.0128000000000000;0.0184000000000000;0.0240000000000000;0.0296000000000000;0.0352000000000000;0.0408000000000000;0.0464000000000000;0.0520000000000000;0.0576000000000000;0.0632000000000000;0.0688000000000000;0.0744000000000000;0.124800000000000;0.130400000000000;0.136000000000000;0.141600000000000;0.147200000000000];
x4=[0.0587000000000000;0.0761000000000000;0.0935000000000000;0.110900000000000;0.128300000000000;0.145700000000000;0.163100000000000;0.215300000000000;0.232700000000000;0.250100000000000;0.267500000000000;0.284900000000000;0.302300000000000;0.319700000000000;0.406700000000000;0.476300000000000];
y3=[0.0333300000000000;0.446200000000000;0.0205100000000000;0.0153800000000000;0.0743600000000000;0.0230800000000000;0.0153800000000000;0.125600000000000;0.125600000000000;0.0384600000000000;0.0205100000000000;0.0230800000000000;0.00256400000000000;0.00769200000000000;0.0128200000000000;0.0102600000000000;0.00512800000000000];
y4=[0.0266700000000000;0;0.200000000000000;0.0800000000000000;0.0666700000000000;0.0266700000000000;0.0266700000000000;0.0133300000000000;0.0933300000000000;0.160000000000000;0.146700000000000;0.0800000000000000;0.0533300000000000;0.0133300000000000;0;0.0133300000000000];

plot(x3,y3,'LineWidth',3,'Color',[0 139/255, 139/255]);
hold on;
plot(x4,y4,'--','LineWidth',3,'Color',[1 125/255 64/255]);

legend('User 1','User 2',24,'FontName','Times New Roman');
xlabel('Tapping interval (s)','fontsize',24,'FontName','Times New Roman');
ylabel('Probability','fontsize',24,'FontName','Times New Roman');
set(gca,'fontsize',24,'FontName','Times New Roman');
set(gcf,'position',[100 10 800 400]);
grid on;