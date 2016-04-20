//
//  ALMessageService.h
//  ALChat
//
//  Copyright (c) 2015 AppLozic. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALConstant.h"
#import "ALSyncMessageFeed.h"
#import "ALMessageList.h"
#import "ALMessage.h"
#import "DB_FileMetaInfo.h"
#import "ALUserDetail.h"
#import "ALChannelService.h"
#import  "MessageListRequest.h"
#import "ALMessageInfoResponse.h"

#define NEW_MESSAGE_NOTIFICATION @"newMessageNotification"

@interface ALMessageService : NSObject <NSURLConnectionDataDelegate>

+(void) processLatestMessagesGroupByContact;


+(void) getMessageListForUser:(MessageListRequest*)messageListRequest withCompletion:(void(^)(NSMutableArray * messages, NSError * error, NSMutableArray *userDetailArray)) completion;
    
+(void) sendMessages:(ALMessage *)message withCompletion:(void(^)(NSString * message, NSError * error)) completion;


+(void) getLatestMessageForUser:(NSString *)deviceKeyString withCompletion:(void(^)(NSMutableArray  * message, NSError *error)) completion;

+(void)proessUploadImageForMessage:(ALMessage *)message databaseObj:(DB_FileMetaInfo *)fileMetaInfo uploadURL:(NSString *)uploadURL withdelegate:(id)delegate;

+(void) processImageDownloadforMessage:(ALMessage *) message withdelegate:(id)delegate;

+(ALMessage*) processFileUploadSucess: (ALMessage *)message;

+(void)deleteMessageThread:( NSString * ) contactId orChannelKey:(NSNumber *)channelKey withCompletion:(void (^)(NSString *, NSError *))completion;

+(void )deleteMessage:( NSString * ) keyString andContactId:( NSString * )contactId withCompletion:(void (^)(NSString *, NSError *))completion;

+(void)processPendingMessages;

+(ALMessage*)getMessagefromKeyValuePair:(NSString*)key andValue:(NSString*)value;

-(void)getMessageInformationWithMessageKey:(NSString *)messageKey withCompletionHandler:(void(^)(ALMessageInfoResponse *msgInfo, NSError *theError))completion;

+(void)multiUserSendMessage:(ALMessage *)alMessage
                 toContacts:(NSMutableArray*)contactIdsArray
                   toGroups:(NSMutableArray*)channelKeysArray
             withCompletion:(void(^)(NSString * json, NSError * error)) completion;

+(void)getMessageSENT:(ALMessage*)alMessage  withCompletion:(void (^)( NSMutableArray *, NSError *))completion;
@end