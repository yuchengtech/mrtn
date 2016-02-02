//
//  任务单列表详情
//
//  Created by Mac on 15/12/23.
//  Copyright © 2015年 YusysTechnologies. All rights reserved.
//

#import "YXOrderListDetailController.h"
#import "YXNetworkingManager.h"
#import "MBProgressHUD+Extension.h"
#import "YXURLHelper.h"
#import "YXOrderListDetailRequest.h"
#import "YXOrderListDetailResponse.h"
#import "YXTaskOrderCell.h"
#import "YXOrderDetailController.h"
#import "AFNetworking.h"

@interface YXOrderListDetailController ()<MBProgressHUDDelegate,UITableViewDataSource,UITableViewDelegate>

@property (strong, nonatomic) IBOutlet UITableView *table;

@end


@implementation YXOrderListDetailController {
    
    NSMutableArray<YXTaskOrderInfo> *array;// 结果

}

+ (instancetype)initWithOrderListInfo:(YXOrderListInfo *)orderInfo {
    
    YXOrderListDetailController *detailVC = [[YXOrderListDetailController alloc] init];
    detailVC.orderInfo = orderInfo;
    return detailVC;
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    if ([_controllerInfo.mode isEqual:ORDER_BACKLOG]) {
        self.title = @"待办列表";
    }else if ([_controllerInfo.mode isEqual:ORDER_PROCESSED]) {
        self.title = @"办结列表";
    }
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self refreshData];// 刷新数据
    
}

- (void)refreshData {
    
    MBProgressHUD *progress = [MBProgressHUD showHUDAddedTo:self text:@"正在查询..."];// 读取框
    YXOrderListDetailRequest *request = [[YXOrderListDetailRequest alloc] init];
    request.mcId       = _orderInfo.mcid;// 商户编号
    request.mcName     = _orderInfo.mcName;// 商户名称
    request.taskStatus = _controllerInfo.mode;// 任务单状态
    [YXNetworkingManager queryWithRequest:request success:^(id responseObject) {
        [progress hide:YES];// 隐藏读取框
        YXOrderListDetailResponse *response = [[YXOrderListDetailResponse alloc] initWithDictionary:responseObject error:nil];
        if (response.success) {
            array = response.data;// 设置数据
            [self.table reloadData];
        }else{
            [MBProgressHUD showFail:response.msg];// 显示错误消息
        }
    } failure:^(void) {
        [progress hide:YES];// 隐藏读取框
        [MBProgressHUD show408];
    }];
    
}

// 显示几个部分
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return 1;
    
}

// 显示多少条数据
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return array.count;
    
}

// 显示cell
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    YXTaskOrderCell *cell = [YXTaskOrderCell cellWithTableView:self.table];
    cell.taskOrderInfo = array[indexPath.row];
    return cell;
    
}

// 点击cell执行方法
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    YXOrderDetailController *controller = [YXOrderDetailController initWithTaskOrderInfo:array[indexPath.row]];
    [self.navigationController pushViewController:controller animated:YES];
    
}


@end
