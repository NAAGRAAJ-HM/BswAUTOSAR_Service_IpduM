/******************************************************************************/
/* File   : IpduM.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgIpduM.hpp"
#include "IpduM_core.hpp"
#include "infIpduM_Exp.hpp"
#include "infIpduM_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define IPDUM_AR_RELEASE_VERSION_MAJOR                                         4
#define IPDUM_AR_RELEASE_VERSION_MINOR                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(IPDUM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible IPDUM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(IPDUM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible IPDUM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_IpduM:
      INTERFACES_EXPORTED_IPDUM
      public abstract_module
   ,  public class_IpduM_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};
            infPduRClient_Lo        infPduRClient_IpduM;

   public:
      module_IpduM(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, IPDUM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, IPDUM_CONFIG_DATA, IPDUM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, IPDUM_CODE) DeInitFunction (void);
      FUNC(void, IPDUM_CODE) MainFunction   (void);
      IPDUM_CORE_FUNCTIONALITIES
};

extern VAR(module_IpduM, IPDUM_VAR) IpduM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, IPDUM_VAR, IPDUM_CONST) gptrinfEcuMClient_IpduM = &IpduM;
CONSTP2VAR(infDcmClient,  IPDUM_VAR, IPDUM_CONST) gptrinfDcmClient_IpduM  = &IpduM;
CONSTP2VAR(infSchMClient, IPDUM_VAR, IPDUM_CONST) gptrinfSchMClient_IpduM = &IpduM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_IpduM, IPDUM_VAR) IpduM(
   {
         IPDUM_AR_RELEASE_VERSION_MAJOR
      ,  IPDUM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, IPDUM_CODE) module_IpduM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, IPDUM_CONFIG_DATA, IPDUM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == IpduM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgIpduM;
         }
      }
      else{
#if(STD_ON == IpduM_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == IpduM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == IpduM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  IPDUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, IPDUM_CODE) module_IpduM::DeInitFunction(void){
#if(STD_ON == IpduM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == IpduM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == IpduM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  IPDUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, IPDUM_CODE) module_IpduM::MainFunction(void){
#if(STD_ON == IpduM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == IpduM_InitCheck)
   }
   else{
#if(STD_ON == IpduM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  IPDUM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, IPDUM_CODE) module_IpduM::dummy(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
