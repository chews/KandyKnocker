//
//  KandyCallProtocol.h
//  Fring
//
//  Created by Yehonatan Yochpaz on 7/10/14.
//  Copyright (c) 2015 GENBAND-fring. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KandyRecord.h"
#import "KandyCallServiceEnums.h"
#import "KandyCallParticipantProtocol.h"
#import "KandyCallActivityDataRetrievalDelegate.h"
#import "KandyCallTerminationReasonProtocol.h"

@class ActivityRecord;
@class KandyVideoCodecSetting;
/**
 *  This protocol handles a host of informational chores including: 
 *  - ID/state/type of call
 *  - who is being called, when the call turned to "ETalking"
 *  - Call duration in seconds/string
 *  - current call participants/self participant/all participants
 *  - is receiving/sending video, incoming call, started with video, missed, on hold, other participant on hold
 *  - termination reason
 *  - audio: current outgoing route, muted, change the current audio route, retrieve all available output audio routes 
 *  - Get/Set the view for the local/remote video view 
 *  - hangup/transfer/hold/unhold call
 *  - Start/Stop sending video to the other participants
 *  - switch the camera for the outgoing video
 *  - Mute/Unmute the outgoing recorded audio
 *  - Send DTMF tone to the other participant
 */
@protocol KandyCallProtocol <KandyCallActivityDataRetrievalDelegate>

/**
 *  ID of the call
 */
@property(nonatomic, readonly) NSString *callId;
/**
 *  The call state
 */
@property(nonatomic, readonly) EKandyCallState callState;
/**
 *  The call type
 */
@property(nonatomic, readonly) EKandyCallType callType;
/**
 *  The record who is being called @see KandyRecord.h
 */
@property(nonatomic, readonly) KandyRecord* callee;
/**
 *  Indicates the time where the call turned into "ETalking", before that it is undefined (nil)
 */
@property(nonatomic, readonly) NSDate *startTime;
/**
 *  Undefined (nil) if the call is still in progress, or has not started yet
 */
@property(nonatomic, readonly) NSDate *endTime;
/**
 *  Call duration in seconds
 */
@property(readonly) NSTimeInterval duration;
/**
 *  Call duration in string representation
 */
@property(readonly) NSString *durationString;
/**
 *  Array of the current call participants @see KandyCallParticipantProtocol.h
 *  Not containing the self participant
 */
@property(nonatomic, readonly) NSArray *participants;
/**
 *  The self participant @see KandyCallParticipantProtocol.h
 *  Relevant for conference calls
 */
@property(readonly) id<KandyCallParticipantProtocol> selfParticipant;
/**
 *  All the participants in the call so far @see KandyRecord.h
 */
@property(nonatomic, readonly) NSArray *totalCallRecords;
/**
 *  Is recieving video
 */
@property(readonly) BOOL isReceivingVideo;
/**
 *  Is sending video
 */
@property(readonly) BOOL isSendingVideo;
/**
 *  Is incoming call
 */
@property(readonly) BOOL isIncomingCall;
/**
 *  Is call started with video
 */
@property(readonly) BOOL isCallStartedWithVideo;
/**
 *  Is missed call
 */
@property(readonly) BOOL isMissedCall;
/**
 *  Is call on hold
 */
@property(readonly) BOOL isOnHold;
/**
 *  Is other participant on hold
 */
@property(readonly) BOOL isOtherParticipantOnHold;
/**
 *  Termination reason. Exists only after call has been terminated, null otherwise.
 */
@property(nonatomic, readonly) id<KandyCallTerminationReasonProtocol> terminationReason;
/**
 *  The current outgoing audio route
 */
@property(readonly) EKandyCallAudioRoute audioRoute;
/**
 *  Is the outgoing audio muted
 */
@property(readonly) BOOL isMute;
/**
 *  Get the notification waiting state in case we got the call by push
 */
@property(nonatomic, readonly) EKandyIncomingCallAnswerType incomingCallAnswerType;
/**
 *  Get/Set the view for the local video view
 */
@property(strong, nonatomic) UIView *localVideoView;
/**
 *  Get/Set the view for the remote video view
 */
@property(strong, nonatomic) UIView *remoteVideoView;

#pragma mark - call operations
/**
 *  Hangup the call
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) hangupWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Transfer the call to another contact. This method will terminate the current call, and connect the other participant for the contact
 *
 *  @param actionRecord     The contactRecord to which to pass the call
 *  @param responseDelegate the delegate to get the response
 */
//-(void) transfer:(KandyRecord*)record withResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Hold the call
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) holdWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Unhold the call
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) unHoldWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Change the current audio route
 *
 *  @param audioRoute       the required audio route
 *  @param responseDelegate the delegate to get the response
 */
-(void) changeAudioRoute:(EKandyCallAudioRoute)aAudioRoute withResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Retrieve all available output audio routes as array of EKandyAudioRoute
 *
 *  @return Array of EKandyAudioRoute representing the available audio output routes
 */
-(NSArray*) getAvailableAudioOutputs;
/**
 *  Start sending video to the other participants
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) startVideoSharingWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Stop sending video to the other participants
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) stopVideoSharingWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Switch the camera for the outgoing video
 *
 *  @param responseDelegate the delegate to get the response
 */
-(void) switchCameraWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Switch the camera for the outgoing video
 *
 *  @param cameraAlternative the camera alternative to switch the video recording
 *  @param responseDelegate  the delegate to get the response
 */
//-(void) switchCamera:(NSString*)cameraAlternative WithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Mute the outgoing recorded audio
 */
-(void) muteWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Unmute the outgoing recorded audio
 */
-(void) unmuteWithResponseCallback:(void (^)(NSError *error))responseCallback;
/**
 *  Send DTMF tone to the other participant
 *
 *  @param tone the delegate to get the response
 */
-(void) sendDTMF:(char)tone;
@end
