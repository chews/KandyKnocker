//
//  KandyServiceErrors.h
//  Fring
//
//  Created by Tamir Maoz on 7/29/14.
//  Copyright (c) 2015 GENBAND-fring. All rights reserved.
//

#ifndef Fring_KandyServiceErrors_h
#define Fring_KandyServiceErrors_h

/**
 *  Error domain for the family of General errors
 */
static NSString * const KandyGeneralServiceErrorDomain = @"GeneralServiceErrorDomain";

/**
 *  Error codes for the family of General errors
 */
typedef NS_ENUM(NSUInteger, EKandyGeneralServiceError)
{
    /**
     *  General error
     */
    EKandyGeneralServiceError_generalError = 0,
    /**
     *  Method not implemented yet
     */
    EKandyGeneralServiceError_notImplemetedYet,
    /**
     *  Missing parameters
     */
    EKandyGeneralServiceError_missingParameters,
    /**
     *  Internet connection error, e.g. no Internet.
     */
    EKandyGeneralServiceError_networkError = 100,
    /**
     *  Cannot reach host
     */
    EKandyGeneralServiceError_couldNotConnectHost,
    /**
     *  Request timeout
     */
    EKandyGeneralServiceError_requestTimeout,
    /**
     *  Server trying to connect not trusted
     */
    EKandyGeneralServiceError_serverNotTrusted,
    
    /**
     *  Error occured by our system. Please try again later
     */
    EKandyGeneralServiceError_internalServerError = 1000,
    /**
     *  Invalid credentials (domain or user) for processing service operation
     */
    EKandyGeneralServiceError_invalidCredentials,
    /**
     *  The domain for processing service operation got invalid. Need to recreate the domain
     */
    EKandyGeneralServiceError_domainGotInvalid,
    /**
     *  The user for processing service operation got invalid. Need to recreate the user
     */
    EKandyGeneralServiceError_userGotInvalid,
    /**
     *  The domain is temporarily unavailable. Please try again later
     */
    EKandyGeneralServiceError_domainTemporarilyUnavailable,
    /**
     *  The user is temporarily unavailable. Please try again later
     */
    EKandyGeneralServiceError_userTemporarilyUnavailable,
    /**
     *  The user is not allowed to accees the Internet
     */
    EKandyGeneralServiceError_connectionNotAllowed,
    /**
     *  The KandyAPI is not longer supported, needs to upgrade
     */
    EKandyGeneralServiceError_kandyAPINotLongerSupported,
};

#endif

//    EKandyGeneralServiceError_tokenExpired,
//    EKandyGeneralServiceError_noValidatedUser,
//    EKandyGeneralServiceError_missingParameters,
//    EKandyGeneralServiceError_badRequest,
//    EKandyGeneralServiceError_userNotFound,
//    EKandyGeneralServiceError_SQL_XMLError,
//    EKandyGeneralServiceError_userOffline,
//    EKandyGeneralServiceError_phoneNumberNormalizationFailed,
//    EKandyGeneralServiceError_badParameter,
//    EKandyGeneralServiceError_unconfirmedUserId,
//    EKandyGeneralServiceError_permissionDenied,
//    EKandyGeneralServiceError_invalidParameterValue,
//    EKandyGeneralServiceError_unknownRequest,
//    EKandyGeneralServiceError_noData,
//    EKandyGeneralServiceError_billingUserNotFound,
//    EKandyGeneralServiceError_mergeAccountsWrongBillingUserId,
//    EKandyGeneralServiceError_MergeAccountsWrongBillingPassword,
//    EKandyGeneralServiceError_insufficientFunds,
//    EKandyGeneralServiceError_usageQuotaExeeded,
//    EKandyGeneralServiceError_operationCancelled,