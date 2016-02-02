//
//  网络
//
//  Created by Mac on 15/12/21.
//  Copyright © 2015年 YusysTechnologies. All rights reserved.
//

// 服务器地址
#define URL @"http://182.50.120.70:6061/mms/"
// 登录
#define URL_LOGIN [NSString stringWithFormat:@"%@login/appLogin",URL]
// 商户信息
#define URL_QUERY_MCBOOK [NSString stringWithFormat:@"%@mcinfo/query",URL]
// 商户列表
#define URL_MACHINE [NSString stringWithFormat:@"%@machine/list",URL]
// 单个商户
#define URL_QUERY_MERCHANT [NSString stringWithFormat:@"%@mcinfo/queryOne",URL]
// 商户列表
#define URL_ORDER_LIST [NSString stringWithFormat:@"%@taskOrderService/getGroupMcInfo",URL]
// 任务单列表
#define URL_ORDERLIST_DETAIL [NSString stringWithFormat:@"%@taskOrderService/getOrderList",URL]
// 任务单详情
#define URL_ORDER_DETAIL [NSString stringWithFormat:@"%@taskOrder/queryOne",URL]
// 图片上传
#define URL_IMAGE_UPLOAD [NSString stringWithFormat:@"%@servlet/Upload",URL]
// 图片下载
#define URL_IMAGE [NSString stringWithFormat:@"%@resources/upload/task/",URL]
// 任务单提交
#define URL_ORDER_UPLOAD [NSString stringWithFormat:@"%@taskOrderService/PostTaskOrder",URL]
// 关联商户和机具
#define URL_SCAN_UPLOAD [NSString stringWithFormat:@"%@machine/scanCodeUpdate",URL]
// 预计上门时间
#define URL_PREDICT_UPLOAD [NSString stringWithFormat:@"%@taskOrderService/PredictTaskOrder",URL]


@interface YXURLHelper : NSObject

@end
