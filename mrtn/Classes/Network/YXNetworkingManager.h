//
//  网络管理
//
//  Created by Mac on 15/12/21.
//  Copyright © 2015年 YusysTechnologies. All rights reserved.
//

#import "AFNetworking.h"
#import "YXRequest.h"
#import "YXResponse.h"
#import "YXLoginRequest.h"
#import "YXLoginResponse.h"
#import "YXTaskOrderInfo.h"

@interface YXNetworkingManager : NSObject

/**
 *  登录
 *
 *  @param request 登录请求
 *  @param success 登录成功执行方法
 *  @param failure 登录失败执行方法
 *
 *  @return 任务
 */
+ (AFHTTPRequestOperation *)loginWithRequest:(YXLoginRequest *)request success:(void(^)(YXLoginResponse *response))success failure:(void(^)(void))failure;
/**
 *  查询
 *
 *  @param request 查询请求
 *  @param success 查询成功执行方法
 *  @param failure 查询失败执行方法
 *
 *  @return 任务
 */
+ (AFHTTPRequestOperation *)queryWithRequest:(YXRequest *)request success:(void(^)(id responseObject))success failure:(void(^)(void))failure;

/**
 *  上传任务单
 *
 *  @param taskOrderInfo 任务单
 *  @param success       上传成功执行方法
 *  @param failure       上传失败执行方法
 *
 *  @return 任务
 */
+ (AFHTTPRequestOperation *)uploadTaskOrder:(YXTaskOrderInfo *)taskOrderInfo success:(void(^)(id responseObject))success failure:(void(^)(void))failure;

/**
 *  上传图片
 *
 *  @param image   图片
 *  @param success 上传成功执行方法
 *  @param failure 上传失败执行方法
 *
 *  @return 任务
 */
+ (AFHTTPRequestOperation *)uploadImage:(UIImage *)image success:(void(^)(id responseObject))success failure:(void(^)(void))failure;

/**
 *  更新
 *
 *  @param request 请求
 *  @param success 更新成功执行方法
 *  @param failure 更新失败执行方法
 *
 *  @return 任务
 */
+ (AFHTTPRequestOperation *)updateWithRequest:(YXRequest *)request success:(void(^)(id responseObject))success failure:(void(^)(void))failure;


@end
