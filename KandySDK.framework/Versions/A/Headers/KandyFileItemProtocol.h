//
//  KandyFileItemProtocol.h
//  KandySDK
//
//  Created by Tamir Maoz on 12/17/14.
//  Copyright (c) 2015 GENBAND-fring. All rights reserved.
//

#import "KandyMediaItemProtocol.h"
#import "KandyTransferProgress.h"

/**
 * Handles the file media item
 */
@protocol KandyFileItemProtocol <KandyMediaItemProtocol>

/**
 *  The UUID for the content
 */
@property (readonly) NSString* contentUUID;
/**
 *  The file name (includes extension)
 */
@property (readonly) NSString* fileName;
/**
 *  The file extension
 */
@property (readonly) NSString* fileExtension;
/**
 *  The file size in bytes
 */
@property (readonly) long long fileSize;
/**
 *  The absolute path for the file
 *  Absolute path may change for some reason e.g., after application version update
 */
@property (readonly) NSString* fileAbsolutePath;
/**
 *  The relative path for the file - does not include the application directory path prefix
 *  Relative path is important since it does not change under any circumstance
 */
@property (readonly) NSString* fileRelativePath;
/**
 *  The date the file was added
 */
@property (readonly) NSDate* dateAdded;
/**
 *  The date the file was modified
 */
@property (readonly) NSDate* dateModified;
/**
 *  The file transfer progress
 */
@property (readonly) KandyTransferProgress* transferProgress;
/**
 *  Update the content UUID e.g once file was successfully uploaded
 *
 *  @param aContentUUID the contentUUID
 */
-(void) updateContentUUID:(NSString*)aContentUUID;

@end


