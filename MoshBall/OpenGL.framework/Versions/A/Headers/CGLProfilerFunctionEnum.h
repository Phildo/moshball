/*
	File:		CGLProfilerFunctionEnum.h
	Copyright:	� 2004 by Apple Computer, Inc., all rights reserved.
*/


#ifndef _CGLPROFILERFUNCTIONENUM_H
#define _CGLPROFILERFUNCTIONENUM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    /* CGL commands */
	kCGLFECGLChoosePixelFormat = 0,
	kCGLFECGLClearDrawable,
	kCGLFECGLComment,
	kCGLFECGLCopyContext,
	kCGLFECGLCreateContext,
	kCGLFECGLCreatePBuffer,
	kCGLFECGLDescribePBuffer,
	kCGLFECGLDescribePixelFormat,
	kCGLFECGLDescribeRenderer,
	kCGLFECGLDestroyContext,
	kCGLFECGLDestroyPBuffer,
	kCGLFECGLDestroyPixelFormat,
	kCGLFECGLDestroyRendererInfo,
	kCGLFECGLDisable,
	kCGLFECGLEnable,
	kCGLFECGLFlushDrawable,
	kCGLFECGLGetCurrentContext,
	kCGLFECGLGetFullScreen,
	kCGLFECGLGetOffScreen,
	kCGLFECGLGetOption,
	kCGLFECGLGetParameter,
	kCGLFECGLGetPBuffer,
	kCGLFECGLGetSurface,
	kCGLFECGLGetVersion,
	kCGLFECGLGetVirtualScreen,
	kCGLFECGLIsEnabled,
	kCGLFECGLQueryRendererInfo,
	kCGLFECGLSetCurrentContext,
	kCGLFECGLSetFullScreen,
	kCGLFECGLSetOffScreen,
	kCGLFECGLSetOption,
	kCGLFECGLSetParameter,
	kCGLFECGLSetPBuffer,
	kCGLFECGLSetSurface,
	kCGLFECGLSetVirtualScreen,
	kCGLFECGLTexImagePBuffer,
	kCGLFECGLUpdateContext,

    /* OpenGL commands */
	kCGLFEglAccum,
	kCGLFEglActiveStencilFaceEXT,
	kCGLFEglActiveTexture,
	kCGLFEglAlphaFunc,
	kCGLFEglAreTexturesResident,
	kCGLFEglArrayElement,
	kCGLFEglAttachShader,
	kCGLFEglBegin,
	kCGLFEglBeginQuery,
	kCGLFEglBindAttribLocation,
	kCGLFEglBindBuffer,
	kCGLFEglBindFramebufferEXT,
	kCGLFEglBindProgramARB,
	kCGLFEglBindRenderbufferEXT,
	kCGLFEglBindTexture,
	kCGLFEglBindVertexArrayEXT,
	kCGLFEglBitmap,
	kCGLFEglBlendColor,
	kCGLFEglBlendEquation,
	kCGLFEglBlendEquationSeparate,
	kCGLFEglBlendFunc,
	kCGLFEglBlendFuncSeparate,
	kCGLFEglBufferData,
	kCGLFEglBufferSubData,
	kCGLFEglCallList,
	kCGLFEglCallLists,
	kCGLFEglCheckFramebufferStatusEXT,
	kCGLFEglClear,
	kCGLFEglClearAccum,
	kCGLFEglClearColor,
	kCGLFEglClearDepth,
	kCGLFEglClearIndex,
	kCGLFEglClearStencil,
	kCGLFEglClientActiveTexture,
	kCGLFEglClipPlane,
	kCGLFEglColor3b,
	kCGLFEglColor3bv,
	kCGLFEglColor3d,
	kCGLFEglColor3dv,
	kCGLFEglColor3f,
	kCGLFEglColor3fv,
	kCGLFEglColor3i,
	kCGLFEglColor3iv,
	kCGLFEglColor3s,
	kCGLFEglColor3sv,
	kCGLFEglColor3ub,
	kCGLFEglColor3ubv,
	kCGLFEglColor3ui,
	kCGLFEglColor3uiv,
	kCGLFEglColor3us,
	kCGLFEglColor3usv,
	kCGLFEglColor4b,
	kCGLFEglColor4bv,
	kCGLFEglColor4d,
	kCGLFEglColor4dv,
	kCGLFEglColor4f,
	kCGLFEglColor4fv,
	kCGLFEglColor4i,
	kCGLFEglColor4iv,
	kCGLFEglColor4s,
	kCGLFEglColor4sv,
	kCGLFEglColor4ub,
	kCGLFEglColor4ubv,
	kCGLFEglColor4ui,
	kCGLFEglColor4uiv,
	kCGLFEglColor4us,
	kCGLFEglColor4usv,
	kCGLFEglColorMask,
	kCGLFEglColorMaterial,
	kCGLFEglColorPointer,
	kCGLFEglColorSubTable,
	kCGLFEglColorTable,
	kCGLFEglColorTableParameterfv,
	kCGLFEglColorTableParameteriv,
	kCGLFEglCombinerInputNV,
	kCGLFEglCombinerOutputNV,
	kCGLFEglCombinerParameterfNV,
	kCGLFEglCombinerParameterfvNV,
	kCGLFEglCombinerParameteriNV,
	kCGLFEglCombinerParameterivNV,
	kCGLFEglCombinerStageParameterfvNV,
	kCGLFEglCompileShader,
	kCGLFEglCompressedTexImage1D,
	kCGLFEglCompressedTexImage2D,
	kCGLFEglCompressedTexImage3D,
	kCGLFEglCompressedTexSubImage1D,
	kCGLFEglCompressedTexSubImage2D,
	kCGLFEglCompressedTexSubImage3D,
	kCGLFEglConvolutionFilter1D,
	kCGLFEglConvolutionFilter2D,
	kCGLFEglConvolutionParameterf,
	kCGLFEglConvolutionParameterfv,
	kCGLFEglConvolutionParameteri,
	kCGLFEglConvolutionParameteriv,
	kCGLFEglCopyColorSubTable,
	kCGLFEglCopyColorTable,
	kCGLFEglCopyConvolutionFilter1D,
	kCGLFEglCopyConvolutionFilter2D,
	kCGLFEglCopyPixels,
	kCGLFEglCopyTexImage1D,
	kCGLFEglCopyTexImage2D,
	kCGLFEglCopyTexSubImage1D,
	kCGLFEglCopyTexSubImage2D,
	kCGLFEglCopyTexSubImage3D,
	kCGLFEglCreateProgramObjectARB,
	kCGLFEglCreateShaderObjectARB,
	kCGLFEglCullFace,
	kCGLFEglDeleteBuffers,
	kCGLFEglDeleteFencesAPPLE,
	kCGLFEglDeleteFramebuffersEXT,
	kCGLFEglDeleteLists,
	kCGLFEglDeleteObjectARB,
	kCGLFEglDeleteProgramsARB,
	kCGLFEglDeleteQueries,
	kCGLFEglDeleteRenderbuffersEXT,
	kCGLFEglDeleteTextures,
	kCGLFEglDeleteVertexArraysEXT,
	kCGLFEglDepthBoundsEXT,
	kCGLFEglDepthFunc,
	kCGLFEglDepthMask,
	kCGLFEglDepthRange,
	kCGLFEglDetachObjectARB,
	kCGLFEglDisable,
	kCGLFEglDisableClientState,
	kCGLFEglDisableVertexAttribAPPLE,
	kCGLFEglDisableVertexAttribArray,
	kCGLFEglDrawArrays,
	kCGLFEglDrawBuffer,
	kCGLFEglDrawBuffersARB,
	kCGLFEglDrawElementArrayAPPLE,
	kCGLFEglDrawElements,
	kCGLFEglDrawPixels,
	kCGLFEglDrawRangeElementArrayAPPLE,
	kCGLFEglDrawRangeElements,
	kCGLFEglEdgeFlag,
	kCGLFEglEdgeFlagPointer,
	kCGLFEglEdgeFlagv,
	kCGLFEglElementPointerAPPLE,
	kCGLFEglEnable,
	kCGLFEglEnableClientState,
	kCGLFEglEnableVertexAttribAPPLE,
	kCGLFEglEnableVertexAttribArray,
	kCGLFEglEnd,
	kCGLFEglEndList,
	kCGLFEglEndQuery,
	kCGLFEglEvalCoord1d,
	kCGLFEglEvalCoord1dv,
	kCGLFEglEvalCoord1f,
	kCGLFEglEvalCoord1fv,
	kCGLFEglEvalCoord2d,
	kCGLFEglEvalCoord2dv,
	kCGLFEglEvalCoord2f,
	kCGLFEglEvalCoord2fv,
	kCGLFEglEvalMesh1,
	kCGLFEglEvalMesh2,
	kCGLFEglEvalPoint1,
	kCGLFEglEvalPoint2,
	kCGLFEglFeedbackBuffer,
	kCGLFEglFinalCombinerInputNV,
	kCGLFEglFinish,
	kCGLFEglFinishFenceAPPLE,
	kCGLFEglFinishObjectAPPLE,
	kCGLFEglFinishRenderAPPLE,
	kCGLFEglFlush,
	kCGLFEglFlushRenderAPPLE,
	kCGLFEglFlushVertexArrayRangeAPPLE,
	kCGLFEglFogCoordPointer,
	kCGLFEglFogCoordd,
	kCGLFEglFogCoorddv,
	kCGLFEglFogCoordf,
	kCGLFEglFogCoordfv,
	kCGLFEglFogf,
	kCGLFEglFogfv,
	kCGLFEglFogi,
	kCGLFEglFogiv,
	kCGLFEglFramebufferRenderbufferEXT,
	kCGLFEglFramebufferTexture1DEXT,
	kCGLFEglFramebufferTexture2DEXT,
	kCGLFEglFramebufferTexture3DEXT,
	kCGLFEglFrontFace,
	kCGLFEglFrustum,
	kCGLFEglGenBuffers,
	kCGLFEglGenerateMipmapEXT,
	kCGLFEglGenFencesAPPLE,
	kCGLFEglGenFramebuffersEXT,
	kCGLFEglGenLists,
	kCGLFEglGenProgramsARB,
	kCGLFEglGenQueries,
	kCGLFEglGenRenderbuffersEXT,
	kCGLFEglGenTextures,
	kCGLFEglGenVertexArraysAPPLE,
	kCGLFEglGetActiveAttrib,
	kCGLFEglGetActiveUniform,
	kCGLFEglGetAttachedObjectsARB,
	kCGLFEglGetAttribLocation,
	kCGLFEglGetBooleanv,
	kCGLFEglGetBufferParameteriv,
	kCGLFEglGetBufferPointerv,
	kCGLFEglGetBufferSubData,
	kCGLFEglGetClipPlane,
	kCGLFEglGetColorTable,
	kCGLFEglGetColorTableParameterfv,
	kCGLFEglGetColorTableParameteriv,
	kCGLFEglGetCombinerInputParameterfvNV,
	kCGLFEglGetCombinerInputParameterivNV,
	kCGLFEglGetCombinerOutputParameterfvNV,
	kCGLFEglGetCombinerOutputParameterivNV,
	kCGLFEglGetCombinerStageParameterfvNV,
	kCGLFEglGetCompressedTexImage,
	kCGLFEglGetConvolutionFilter,
	kCGLFEglGetConvolutionParameterfv,
	kCGLFEglGetConvolutionParameteriv,
	kCGLFEglGetDoublev,
	kCGLFEglGetError,
	kCGLFEglGetFinalCombinerInputParameterfvNV,
	kCGLFEglGetFinalCombinerInputParameterivNV,
	kCGLFEglGetFloatv,
	kCGLFEglGetFramebufferAttachmentParameterivEXT,
	kCGLFEglGetHandleARB,
	kCGLFEglGetHistogram,
	kCGLFEglGetHistogramParameterfv,
	kCGLFEglGetHistogramParameteriv,
	kCGLFEglGetInfoLogARB,
	kCGLFEglGetIntegerv,
	kCGLFEglGetLightfv,
	kCGLFEglGetLightiv,
	kCGLFEglGetMapdv,
	kCGLFEglGetMapfv,
	kCGLFEglGetMapiv,
	kCGLFEglGetMaterialfv,
	kCGLFEglGetMaterialiv,
	kCGLFEglGetMinmax,
	kCGLFEglGetMinmaxParameterfv,
	kCGLFEglGetMinmaxParameteriv,
	kCGLFEglGetObjectParameterfvARB,
	kCGLFEglGetObjectParameterivARB,
	kCGLFEglGetPixelMapfv,
	kCGLFEglGetPixelMapuiv,
	kCGLFEglGetPixelMapusv,
	kCGLFEglGetPointerv,
	kCGLFEglGetPolygonStipple,
	kCGLFEglGetProgramEnvParameterdvARB,
	kCGLFEglGetProgramEnvParameterfvARB,
	kCGLFEglGetProgramInfoLog,
	kCGLFEglGetProgramLocalParameterdvARB,
	kCGLFEglGetProgramLocalParameterfvARB,
	kCGLFEglGetProgramStringARB,
	kCGLFEglGetProgramiv,
	kCGLFEglGetProgramivARB,
	kCGLFEglGetQueryObjectiv,
	kCGLFEglGetQueryObjectuiv,
	kCGLFEglGetQueryiv,
	kCGLFEglGetRenderbufferParameterivEXT,
	kCGLFEglGetSeparableFilter,
	kCGLFEglGetShaderInfoLog,
	kCGLFEglGetShaderSource,
	kCGLFEglGetShaderiv,
	kCGLFEglGetString,
	kCGLFEglGetTexEnvfv,
	kCGLFEglGetTexEnviv,
	kCGLFEglGetTexGendv,
	kCGLFEglGetTexGenfv,
	kCGLFEglGetTexGeniv,
	kCGLFEglGetTexImage,
	kCGLFEglGetTexLevelParameterfv,
	kCGLFEglGetTexLevelParameteriv,
	kCGLFEglGetTexParameterPointervAPPLE,
	kCGLFEglGetTexParameterfv,
	kCGLFEglGetTexParameteriv,
	kCGLFEglGetUniformLocation,
	kCGLFEglGetUniformfv,
	kCGLFEglGetUniformiv,
	kCGLFEglGetVertexAttribPointerv,
	kCGLFEglGetVertexAttribdv,
	kCGLFEglGetVertexAttribfv,
	kCGLFEglGetVertexAttribiv,
	kCGLFEglHint,
	kCGLFEglHistogram,
	kCGLFEglIndexMask,
	kCGLFEglIndexPointer,
	kCGLFEglIndexd,
	kCGLFEglIndexdv,
	kCGLFEglIndexf,
	kCGLFEglIndexfv,
	kCGLFEglIndexi,
	kCGLFEglIndexiv,
	kCGLFEglIndexs,
	kCGLFEglIndexsv,
	kCGLFEglIndexub,
	kCGLFEglIndexubv,
	kCGLFEglInitNames,
	kCGLFEglInterleavedArrays,
	kCGLFEglIsBuffer,
	kCGLFEglIsEnabled,
	kCGLFEglIsFenceAPPLE,
	kCGLFEglIsFramebufferEXT,
	kCGLFEglIsList,
	kCGLFEglIsProgram,
	kCGLFEglIsProgramARB,
	kCGLFEglIsQuery,
	kCGLFEglIsRenderbufferEXT,
	kCGLFEglIsShader,
	kCGLFEglIsTexture,
	kCGLFEglIsVertexArrayAPPLE,
	kCGLFEglIsVertexAttribEnabledAPPLE,
	kCGLFEglLightModelf,
	kCGLFEglLightModelfv,
	kCGLFEglLightModeli,
	kCGLFEglLightModeliv,
	kCGLFEglLightf,
	kCGLFEglLightfv,
	kCGLFEglLighti,
	kCGLFEglLightiv,
	kCGLFEglLineStipple,
	kCGLFEglLineWidth,
	kCGLFEglLinkProgram,
	kCGLFEglListBase,
	kCGLFEglLoadIdentity,
	kCGLFEglLoadMatrixd,
	kCGLFEglLoadMatrixf,
	kCGLFEglLoadName,
	kCGLFEglLoadTransposeMatrixd,
	kCGLFEglLoadTransposeMatrixf,
	kCGLFEglLockArraysEXT,
	kCGLFEglLogicOp,
	kCGLFEglMap1d,
	kCGLFEglMap1f,
	kCGLFEglMap2d,
	kCGLFEglMap2f,
	kCGLFEglMapBuffer,
	kCGLFEglMapGrid1d,
	kCGLFEglMapGrid1f,
	kCGLFEglMapGrid2d,
	kCGLFEglMapGrid2f,
	kCGLFEglMapVertexAttrib1dAPPLE,
	kCGLFEglMapVertexAttrib1fAPPLE,
	kCGLFEglMapVertexAttrib2dAPPLE,
	kCGLFEglMapVertexAttrib2fAPPLE,
	kCGLFEglMaterialf,
	kCGLFEglMaterialfv,
	kCGLFEglMateriali,
	kCGLFEglMaterialiv,
	kCGLFEglMatrixMode,
	kCGLFEglMinmax,
	kCGLFEglMultMatrixd,
	kCGLFEglMultMatrixf,
	kCGLFEglMultTransposeMatrixd,
	kCGLFEglMultTransposeMatrixf,
	kCGLFEglMultiDrawArrays,
	kCGLFEglMultiDrawElementArrayAPPLE,
	kCGLFEglMultiDrawElements,
	kCGLFEglMultiDrawRangeElementArrayAPPLE,
	kCGLFEglMultiTexCoord1d,
	kCGLFEglMultiTexCoord1dv,
	kCGLFEglMultiTexCoord1f,
	kCGLFEglMultiTexCoord1fv,
	kCGLFEglMultiTexCoord1i,
	kCGLFEglMultiTexCoord1iv,
	kCGLFEglMultiTexCoord1s,
	kCGLFEglMultiTexCoord1sv,
	kCGLFEglMultiTexCoord2d,
	kCGLFEglMultiTexCoord2dv,
	kCGLFEglMultiTexCoord2f,
	kCGLFEglMultiTexCoord2fv,
	kCGLFEglMultiTexCoord2i,
	kCGLFEglMultiTexCoord2iv,
	kCGLFEglMultiTexCoord2s,
	kCGLFEglMultiTexCoord2sv,
	kCGLFEglMultiTexCoord3d,
	kCGLFEglMultiTexCoord3dv,
	kCGLFEglMultiTexCoord3f,
	kCGLFEglMultiTexCoord3fv,
	kCGLFEglMultiTexCoord3i,
	kCGLFEglMultiTexCoord3iv,
	kCGLFEglMultiTexCoord3s,
	kCGLFEglMultiTexCoord3sv,
	kCGLFEglMultiTexCoord4d,
	kCGLFEglMultiTexCoord4dv,
	kCGLFEglMultiTexCoord4f,
	kCGLFEglMultiTexCoord4fv,
	kCGLFEglMultiTexCoord4i,
	kCGLFEglMultiTexCoord4iv,
	kCGLFEglMultiTexCoord4s,
	kCGLFEglMultiTexCoord4sv,
	kCGLFEglNewList,
	kCGLFEglNormal3b,
	kCGLFEglNormal3bv,
	kCGLFEglNormal3d,
	kCGLFEglNormal3dv,
	kCGLFEglNormal3f,
	kCGLFEglNormal3fv,
	kCGLFEglNormal3i,
	kCGLFEglNormal3iv,
	kCGLFEglNormal3s,
	kCGLFEglNormal3sv,
	kCGLFEglNormalPointer,
	kCGLFEglOrtho,
	kCGLFEglPassThrough,
	kCGLFEglPixelMapfv,
	kCGLFEglPixelMapuiv,
	kCGLFEglPixelMapusv,
	kCGLFEglPixelStoref,
	kCGLFEglPixelStorei,
	kCGLFEglPixelTransferf,
	kCGLFEglPixelTransferi,
	kCGLFEglPixelZoom,
	kCGLFEglPNTrianglesfATI,
	kCGLFEglPNTrianglesiATI,
	kCGLFEglPointParameterf,
	kCGLFEglPointParameterfv,
	kCGLFEglPointParameteri,
	kCGLFEglPointParameteriv,
	kCGLFEglPointSize,
	kCGLFEglPolygonMode,
	kCGLFEglPolygonOffset,
	kCGLFEglPolygonStipple,
	kCGLFEglPopAttrib,
	kCGLFEglPopClientAttrib,
	kCGLFEglPopMatrix,
	kCGLFEglPopName,
	kCGLFEglPrioritizeTextures,
	kCGLFEglProgramEnvParameter4dARB,
	kCGLFEglProgramEnvParameter4dvARB,
	kCGLFEglProgramEnvParameter4fARB,
	kCGLFEglProgramEnvParameter4fvARB,
	kCGLFEglProgramLocalParameter4dARB,
	kCGLFEglProgramLocalParameter4dvARB,
	kCGLFEglProgramLocalParameter4fARB,
	kCGLFEglProgramLocalParameter4fvARB,
	kCGLFEglProgramStringARB,
	kCGLFEglPushAttrib,
	kCGLFEglPushClientAttrib,
	kCGLFEglPushMatrix,
	kCGLFEglPushName,
	kCGLFEglRasterPos2d,
	kCGLFEglRasterPos2dv,
	kCGLFEglRasterPos2f,
	kCGLFEglRasterPos2fv,
	kCGLFEglRasterPos2i,
	kCGLFEglRasterPos2iv,
	kCGLFEglRasterPos2s,
	kCGLFEglRasterPos2sv,
	kCGLFEglRasterPos3d,
	kCGLFEglRasterPos3dv,
	kCGLFEglRasterPos3f,
	kCGLFEglRasterPos3fv,
	kCGLFEglRasterPos3i,
	kCGLFEglRasterPos3iv,
	kCGLFEglRasterPos3s,
	kCGLFEglRasterPos3sv,
	kCGLFEglRasterPos4d,
	kCGLFEglRasterPos4dv,
	kCGLFEglRasterPos4f,
	kCGLFEglRasterPos4fv,
	kCGLFEglRasterPos4i,
	kCGLFEglRasterPos4iv,
	kCGLFEglRasterPos4s,
	kCGLFEglRasterPos4sv,
	kCGLFEglReadBuffer,
	kCGLFEglReadPixels,
	kCGLFEglRectd,
	kCGLFEglRectdv,
	kCGLFEglRectf,
	kCGLFEglRectfv,
	kCGLFEglRecti,
	kCGLFEglRectiv,
	kCGLFEglRects,
	kCGLFEglRectsv,
	kCGLFEglRenderbufferStorageEXT,
	kCGLFEglRenderMode,
	kCGLFEglResetHistogram,
	kCGLFEglResetMinmax,
	kCGLFEglRotated,
	kCGLFEglRotatef,
	kCGLFEglSampleCoverage,
	kCGLFEglScaled,
	kCGLFEglScalef,
	kCGLFEglScissor,
	kCGLFEglSecondaryColor3b,
	kCGLFEglSecondaryColor3bv,
	kCGLFEglSecondaryColor3d,
	kCGLFEglSecondaryColor3dv,
	kCGLFEglSecondaryColor3f,
	kCGLFEglSecondaryColor3fv,
	kCGLFEglSecondaryColor3i,
	kCGLFEglSecondaryColor3iv,
	kCGLFEglSecondaryColor3s,
	kCGLFEglSecondaryColor3sv,
	kCGLFEglSecondaryColor3ub,
	kCGLFEglSecondaryColor3ubv,
	kCGLFEglSecondaryColor3ui,
	kCGLFEglSecondaryColor3uiv,
	kCGLFEglSecondaryColor3us,
	kCGLFEglSecondaryColor3usv,
	kCGLFEglSecondaryColorPointer,
	kCGLFEglSelectBuffer,
	kCGLFEglSeparableFilter2D,
	kCGLFEglSetFenceAPPLE,
	kCGLFEglShadeModel,
	kCGLFEglShaderSourceARB,
	kCGLFEglStencilFunc,
	kCGLFEglStencilFuncSeparate,
	kCGLFEglStencilFuncSeparateATI,
	kCGLFEglStencilMask,
	kCGLFEglStencilMaskSeparate,
	kCGLFEglStencilOp,
	kCGLFEglStencilOpSeparate,
	kCGLFEglTestFenceAPPLE,
	kCGLFEglTestObjectAPPLE,
	kCGLFEglTexCoord1d,
	kCGLFEglTexCoord1dv,
	kCGLFEglTexCoord1f,
	kCGLFEglTexCoord1fv,
	kCGLFEglTexCoord1i,
	kCGLFEglTexCoord1iv,
	kCGLFEglTexCoord1s,
	kCGLFEglTexCoord1sv,
	kCGLFEglTexCoord2d,
	kCGLFEglTexCoord2dv,
	kCGLFEglTexCoord2f,
	kCGLFEglTexCoord2fv,
	kCGLFEglTexCoord2i,
	kCGLFEglTexCoord2iv,
	kCGLFEglTexCoord2s,
	kCGLFEglTexCoord2sv,
	kCGLFEglTexCoord3d,
	kCGLFEglTexCoord3dv,
	kCGLFEglTexCoord3f,
	kCGLFEglTexCoord3fv,
	kCGLFEglTexCoord3i,
	kCGLFEglTexCoord3iv,
	kCGLFEglTexCoord3s,
	kCGLFEglTexCoord3sv,
	kCGLFEglTexCoord4d,
	kCGLFEglTexCoord4dv,
	kCGLFEglTexCoord4f,
	kCGLFEglTexCoord4fv,
	kCGLFEglTexCoord4i,
	kCGLFEglTexCoord4iv,
	kCGLFEglTexCoord4s,
	kCGLFEglTexCoord4sv,
	kCGLFEglTexCoordPointer,
	kCGLFEglTexEnvf,
	kCGLFEglTexEnvfv,
	kCGLFEglTexEnvi,
	kCGLFEglTexEnviv,
	kCGLFEglTexGend,
	kCGLFEglTexGendv,
	kCGLFEglTexGenf,
	kCGLFEglTexGenfv,
	kCGLFEglTexGeni,
	kCGLFEglTexGeniv,
	kCGLFEglTexImage1D,
	kCGLFEglTexImage2D,
	kCGLFEglTexImage3D,
	kCGLFEglTexParameterf,
	kCGLFEglTexParameterfv,
	kCGLFEglTexParameteri,
	kCGLFEglTexParameteriv,
	kCGLFEglTexSubImage1D,
	kCGLFEglTexSubImage2D,
	kCGLFEglTexSubImage3D,
	kCGLFEglTextureRangeAPPLE,
	kCGLFEglTranslated,
	kCGLFEglTranslatef,

	kCGLFEglUniform1f,
	kCGLFEglUniform1fv,
	kCGLFEglUniform1i,
	kCGLFEglUniform1iv,
	kCGLFEglUniform2f,
	kCGLFEglUniform2fv,
	kCGLFEglUniform2i,
	kCGLFEglUniform2iv,
	kCGLFEglUniform3f,
	kCGLFEglUniform3fv,
	kCGLFEglUniform3i,
	kCGLFEglUniform3iv,
	kCGLFEglUniform4f,
	kCGLFEglUniform4fv,
	kCGLFEglUniform4i,
	kCGLFEglUniform4iv,
	kCGLFEglUniformMatrix2fv,
	kCGLFEglUniformMatrix3fv,
	kCGLFEglUniformMatrix4fv,

	kCGLFEglUnlockArraysEXT,
	kCGLFEglUnmapBuffer,
	kCGLFEglUseProgram,
	kCGLFEglValidateProgram,
	kCGLFEglVertex2d,
	kCGLFEglVertex2dv,
	kCGLFEglVertex2f,
	kCGLFEglVertex2fv,
	kCGLFEglVertex2i,
	kCGLFEglVertex2iv,
	kCGLFEglVertex2s,
	kCGLFEglVertex2sv,
	kCGLFEglVertex3d,
	kCGLFEglVertex3dv,
	kCGLFEglVertex3f,
	kCGLFEglVertex3fv,
	kCGLFEglVertex3i,
	kCGLFEglVertex3iv,
	kCGLFEglVertex3s,
	kCGLFEglVertex3sv,
	kCGLFEglVertex4d,
	kCGLFEglVertex4dv,
	kCGLFEglVertex4f,
	kCGLFEglVertex4fv,
	kCGLFEglVertex4i,
	kCGLFEglVertex4iv,
	kCGLFEglVertex4s,
	kCGLFEglVertex4sv,
	kCGLFEglVertexArrayParameteriAPPLE,
	kCGLFEglVertexArrayRangeEXT,
	kCGLFEglVertexAttrib1dARB,
	kCGLFEglVertexAttrib1dvARB,
	kCGLFEglVertexAttrib1fARB,
	kCGLFEglVertexAttrib1fvARB,
	kCGLFEglVertexAttrib1sARB,
	kCGLFEglVertexAttrib1svARB,
	kCGLFEglVertexAttrib2dARB,
	kCGLFEglVertexAttrib2dvARB,
	kCGLFEglVertexAttrib2fARB,
	kCGLFEglVertexAttrib2fvARB,
	kCGLFEglVertexAttrib2sARB,
	kCGLFEglVertexAttrib2svARB,
	kCGLFEglVertexAttrib3dARB,
	kCGLFEglVertexAttrib3dvARB,
	kCGLFEglVertexAttrib3fARB,
	kCGLFEglVertexAttrib3fvARB,
	kCGLFEglVertexAttrib3sARB,
	kCGLFEglVertexAttrib3svARB,
	kCGLFEglVertexAttrib4bvARB,
	kCGLFEglVertexAttrib4dARB,
	kCGLFEglVertexAttrib4dvARB,
	kCGLFEglVertexAttrib4fARB,
	kCGLFEglVertexAttrib4fvARB,
	kCGLFEglVertexAttrib4ivARB,
	
	kCGLFEglVertexAttrib4Nbv,
	kCGLFEglVertexAttrib4Niv,
	kCGLFEglVertexAttrib4Nsv,
	kCGLFEglVertexAttrib4Nub,
	kCGLFEglVertexAttrib4Nubv,
	kCGLFEglVertexAttrib4Nuiv,
	kCGLFEglVertexAttrib4Nusv,

	kCGLFEglVertexAttrib4sARB,
	kCGLFEglVertexAttrib4svARB,
	kCGLFEglVertexAttrib4ubvARB,
	kCGLFEglVertexAttrib4uivARB,
	kCGLFEglVertexAttrib4usvARB,
	kCGLFEglVertexAttribPointerARB,

	kCGLFEglVertexBlendARB,
	kCGLFEglVertexPointer,
	kCGLFEglViewport,
	kCGLFEglWeightPointerARB,
	kCGLFEglWeightbvARB,
	kCGLFEglWeightdvARB,
	kCGLFEglWeightfvARB,
	kCGLFEglWeightivARB,
	kCGLFEglWeightsvARB,
	kCGLFEglWeightubvARB,
	kCGLFEglWeightuivARB,
	kCGLFEglWeightusvARB,
	kCGLFEglWindowPos2d,
	kCGLFEglWindowPos2dv,
	kCGLFEglWindowPos2f,
	kCGLFEglWindowPos2fv,
	kCGLFEglWindowPos2i,
	kCGLFEglWindowPos2iv,
	kCGLFEglWindowPos2s,
	kCGLFEglWindowPos2sv,
	kCGLFEglWindowPos3d,
	kCGLFEglWindowPos3dv,
	kCGLFEglWindowPos3f,
	kCGLFEglWindowPos3fv,
	kCGLFEglWindowPos3i,
	kCGLFEglWindowPos3iv,
	kCGLFEglWindowPos3s,
	kCGLFEglWindowPos3sv,

	/* APPLE_flush_buffer_range */
	kCGLFEglBufferParameteriAPPLE,
	kCGLFEglFlushMappedBufferRangeAPPLE,
	
	/* GL_EXT_gpu_program_parameters */
	kCGLFEglProgramEnvParameters4fvEXT,
	kCGLFEglProgramLocalParameters4fvEXT,
	
	/* GL_APPLE_object_purgeable */
	kCGLFEglObjectPurgeableAPPLE,
	kCGLFEglObjectUnpurgeableAPPLE,
	kCGLFEglGetObjectParameterivAPPLE,

	/* GL_EXT_geometry_shader4 */
	kCGLFEglProgramParameteriEXT,
	kCGLFEglFramebufferTextureEXT,
	kCGLFEglFramebufferTextureLayerEXT,
	kCGLFEglFramebufferTextureFaceEXT,

	/* GL_EXT_transform_feedback */
	kCGLFEglBindBufferRangeEXT,
	kCGLFEglBindBufferOffsetEXT,
	kCGLFEglBindBufferBaseEXT,
	kCGLFEglBeginTransformFeedbackEXT,
	kCGLFEglEndTransformFeedbackEXT,
	kCGLFEglTransformFeedbackVaryingsEXT,
	kCGLFEglGetTransformFeedbackVaryingEXT,

	/* GL_EXT_transform_feedback || GL_EXT_draw_buffers2 */
	kCGLFEglGetIntegerIndexedvEXT,
	kCGLFEglGetBooleanIndexedvEXT,

	/* GL_EXT_bindable_uniform */
	kCGLFEglUniformBufferEXT,
	kCGLFEglGetUniformBufferSizeEXT,
	kCGLFEglGetUniformOffsetEXT,

	/* GL_EXT_texture_integer */
	kCGLFEglClearColorIiEXT,
	kCGLFEglClearColorIuiEXT,
	kCGLFEglTexParameterIivEXT,
	kCGLFEglTexParameterIuivEXT,
	kCGLFEglGetTexParameterIivEXT,
	kCGLFEglGetTexParameterIuivEXT,

	/* GL_EXT_gpu_shader4 */
	kCGLFEglVertexAttribI1iEXT,
	kCGLFEglVertexAttribI2iEXT,
	kCGLFEglVertexAttribI3iEXT,
	kCGLFEglVertexAttribI4iEXT,
	kCGLFEglVertexAttribI1uiEXT,
	kCGLFEglVertexAttribI2uiEXT,
	kCGLFEglVertexAttribI3uiEXT,
	kCGLFEglVertexAttribI4uiEXT,
	kCGLFEglVertexAttribI1ivEXT,
	kCGLFEglVertexAttribI2ivEXT,
	kCGLFEglVertexAttribI3ivEXT,
	kCGLFEglVertexAttribI4ivEXT,
	kCGLFEglVertexAttribI1uivEXT,
	kCGLFEglVertexAttribI2uivEXT,
	kCGLFEglVertexAttribI3uivEXT,
	kCGLFEglVertexAttribI4uivEXT,
	kCGLFEglVertexAttribI4bvEXT,
	kCGLFEglVertexAttribI4svEXT,
	kCGLFEglVertexAttribI4ubvEXT,
	kCGLFEglVertexAttribI4usvEXT,
	kCGLFEglVertexAttribIPointerEXT,
	kCGLFEglGetVertexAttribIivEXT,
	kCGLFEglGetVertexAttribIuivEXT,
	kCGLFEglUniform1uiEXT,
	kCGLFEglUniform2uiEXT,
	kCGLFEglUniform3uiEXT,
	kCGLFEglUniform4uiEXT,
	kCGLFEglUniform1uivEXT,
	kCGLFEglUniform2uivEXT,
	kCGLFEglUniform3uivEXT,
	kCGLFEglUniform4uivEXT,
	kCGLFEglGetUniformuivEXT,
	kCGLFEglBindFragDataLocationEXT,
	kCGLFEglGetFragDataLocationEXT,

	/* EXT_draw_buffers2 */
	kCGLFEglColorMaskIndexedEXT,
	kCGLFEglEnableIndexedEXT,
	kCGLFEglDisableIndexedEXT,
	kCGLFEglIsEnabledIndexedEXT,

	/* OpenGL 2.1 */
	kCGLFEglUniformMatrix2x3fv,
	kCGLFEglUniformMatrix3x2fv,
	kCGLFEglUniformMatrix2x4fv,
	kCGLFEglUniformMatrix4x2fv,
	kCGLFEglUniformMatrix3x4fv,
	kCGLFEglUniformMatrix4x3fv,

	/* EXT_framebuffer_blit and EXT_framebuffer_multisample */
	kCGLFEglBlitFramebufferEXT,
	kCGLFEglRenderbufferStorageMultisampleEXT,

	/* NV_conditional_render */
	kCGLFEglBeginConditionalRenderNV,
	kCGLFEglEndConditionalRenderNV,

	/* ARB_color_buffer_float */
	kCGLFEglClampColorARB,

	/* OpenGL 2.1 */
	kCGLFEglGetAttachedShaders,

	/* APPLE_uniform_buffer_object */
	kCGLFEglAttachUniformBufferAPPLE,
	kCGLFEglGetActivePartitionivAPPLE,
	kCGLFEglGetActivePartitionNameAPPLE,
	kCGLFEglGetActiveUniformsivAPPLE,
	kCGLFEglGetActiveUniformsNamesAPPLE,
	kCGLFEglGetPartitionIndexAPPLE,
	kCGLFEglGetUniformIndicesAPPLE,

	/* ARB_instanced_arrays */
	kCGLFEglDrawArraysInstancedARB,
	kCGLFEglDrawElementsInstancedARB,
	kCGLFEglVertexAttribDivisorARB,

	kCGLFEglGetActiveUniformName,
	kCGLFEglGetUniformBlockIndex,
	kCGLFEglGetActiveUniformBlockiv,
	kCGLFEglGetActiveUniformBlockName,

	kCGLFEglSamplePass,

	kCGLFEglProvokingVertexEXT,
	kCGLFEglUniformBlockBinding,
	kCGLFEglGetIntegeri_v,	

	kCGLFENumFunctions,


	/* Aliased Entries ---------------------------------------------------- */


	kCGLFEglIsRenderbuffer   = kCGLFEglIsRenderbufferEXT,
	kCGLFEglBindRenderbuffer = kCGLFEglBindRenderbufferEXT,
	kCGLFEglGenRenderbuffers = kCGLFEglGenRenderbuffersEXT,
	kCGLFEglGetRenderbufferParameteriv = kCGLFEglGetRenderbufferParameterivEXT,
	kCGLFEglIsFramebuffer    = kCGLFEglIsFramebufferEXT,
	kCGLFEglBindFramebuffer  = kCGLFEglBindFramebufferEXT,
	kCGLFEglGenFramebuffers  = kCGLFEglGenFramebuffersEXT,
	kCGLFEglCheckFramebufferStatus = kCGLFEglCheckFramebufferStatusEXT,
	kCGLFEglGetFramebufferAttachmentParameteriv = kCGLFEglGetFramebufferAttachmentParameterivEXT,
	kCGLFEglGenerateMipmap   = kCGLFEglGenerateMipmapEXT,
	kCGLFEglBlitFramebuffer  = kCGLFEglBlitFramebufferEXT,
	kCGLFEglRenderbufferStorageMultisample = kCGLFEglRenderbufferStorageMultisampleEXT,
	kCGLFEglFramebufferTextureLayer = kCGLFEglFramebufferTextureLayerEXT,

	kCGLFEglBindAttribLocationARB = kCGLFEglBindAttribLocation,

	kCGLFEglBlendEquationSeparateEXT = kCGLFEglBlendEquationSeparate,

	kCGLFEglAttachObjectARB  = kCGLFEglAttachShader,
	kCGLFEglCompileShaderARB = kCGLFEglCompileShader,
	kCGLFEglLinkProgramARB   = kCGLFEglLinkProgram,

	kCGLFEglFlushVertexArrayRangeEXT = kCGLFEglFlushVertexArrayRangeAPPLE,

	kCGLFEglGenVertexArraysEXT       = kCGLFEglGenVertexArraysAPPLE,
	kCGLFEglIsVertexArrayEXT         = kCGLFEglIsVertexArrayAPPLE,
	kCGLFEglVertexArrayParameteriEXT = kCGLFEglVertexArrayParameteriAPPLE,

	kCGLFEglGetActiveAttribARB = kCGLFEglGetActiveAttrib,
	kCGLFEglGetActiveUniformARB = kCGLFEglGetActiveUniform,

	kCGLFEglGetAttribLocationARB = kCGLFEglGetAttribLocation,
	kCGLFEglGetShaderSourceARB = kCGLFEglGetShaderSource,
	kCGLFEglGetUniformLocationARB = kCGLFEglGetUniformLocation,
	kCGLFEglGetUniformfvARB = kCGLFEglGetUniformfv,
	kCGLFEglGetUniformivARB = kCGLFEglGetUniformiv,

	kCGLFEglPnTrianglesfATI = kCGLFEglPNTrianglesfATI,
	kCGLFEglPnTrianglesiATI = kCGLFEglPNTrianglesiATI,
	kCGLFEglStencilOpSeparateATI = kCGLFEglStencilOpSeparate,
	kCGLFEglUniform1fARB  = kCGLFEglUniform1f,
	kCGLFEglUniform1fvARB = kCGLFEglUniform1fv,
	kCGLFEglUniform1iARB  = kCGLFEglUniform1i,
	kCGLFEglUniform1ivARB = kCGLFEglUniform1iv,
	kCGLFEglUniform2fARB  = kCGLFEglUniform2f,
	kCGLFEglUniform2fvARB = kCGLFEglUniform2fv,
	kCGLFEglUniform2iARB  = kCGLFEglUniform2i,
	kCGLFEglUniform2ivARB = kCGLFEglUniform2iv,
	kCGLFEglUniform3fARB  = kCGLFEglUniform3f,
	kCGLFEglUniform3fvARB = kCGLFEglUniform3fv,
	kCGLFEglUniform3iARB  = kCGLFEglUniform3i,
	kCGLFEglUniform3ivARB = kCGLFEglUniform3iv,
	kCGLFEglUniform4fARB  = kCGLFEglUniform4f,
	kCGLFEglUniform4fvARB = kCGLFEglUniform4fv,
	kCGLFEglUniform4iARB  = kCGLFEglUniform4i,
	kCGLFEglUniform4ivARB = kCGLFEglUniform4iv,
	kCGLFEglUniformMatrix2fvARB = kCGLFEglUniformMatrix2fv,
	kCGLFEglUniformMatrix3fvARB = kCGLFEglUniformMatrix3fv,
	kCGLFEglUniformMatrix4fvARB = kCGLFEglUniformMatrix4fv,
	kCGLFEglUseProgramObjectARB = kCGLFEglUseProgram,
	kCGLFEglValidateProgramARB = kCGLFEglValidateProgram,

	kCGLFEglDisableVertexAttribARB      = kCGLFEglDisableVertexAttribAPPLE,
	kCGLFEglDisableVertexAttribArrayARB = kCGLFEglDisableVertexAttribArray,
	kCGLFEglEnableVertexAttribARB       = kCGLFEglEnableVertexAttribAPPLE,
	kCGLFEglEnableVertexAttribArrayARB  = kCGLFEglEnableVertexAttribArray,
	kCGLFEglGetVertexAttribPointervARB  = kCGLFEglGetVertexAttribPointerv,
	kCGLFEglGetVertexAttribdvARB        = kCGLFEglGetVertexAttribdv,
	kCGLFEglGetVertexAttribfvARB        = kCGLFEglGetVertexAttribfv,
	kCGLFEglGetVertexAttribivARB        = kCGLFEglGetVertexAttribiv,
	kCGLFEglIsVertexAttribEnabledARB    = kCGLFEglIsVertexAttribEnabledAPPLE,
	kCGLFEglMapVertexAttrib1dARB        = kCGLFEglMapVertexAttrib1dAPPLE,
	kCGLFEglMapVertexAttrib1fARB        = kCGLFEglMapVertexAttrib1fAPPLE,
	kCGLFEglMapVertexAttrib2dARB        = kCGLFEglMapVertexAttrib2dAPPLE,
	kCGLFEglMapVertexAttrib2fARB        = kCGLFEglMapVertexAttrib2fAPPLE,
	kCGLFEglVertexAttribPointer         = kCGLFEglVertexAttribPointerARB,

	kCGLFEglVertexAttrib1d  = kCGLFEglVertexAttrib1dARB,
	kCGLFEglVertexAttrib1dv = kCGLFEglVertexAttrib1dvARB,
	kCGLFEglVertexAttrib1f  = kCGLFEglVertexAttrib1fARB,
	kCGLFEglVertexAttrib1fv = kCGLFEglVertexAttrib1fvARB,
	kCGLFEglVertexAttrib1s  = kCGLFEglVertexAttrib1sARB,
	kCGLFEglVertexAttrib1sv = kCGLFEglVertexAttrib1svARB,
	kCGLFEglVertexAttrib2d  = kCGLFEglVertexAttrib2dARB,
	kCGLFEglVertexAttrib2dv = kCGLFEglVertexAttrib2dvARB,
	kCGLFEglVertexAttrib2f  = kCGLFEglVertexAttrib2fARB,
	kCGLFEglVertexAttrib2fv = kCGLFEglVertexAttrib2fvARB,
	kCGLFEglVertexAttrib2s  = kCGLFEglVertexAttrib2sARB,
	kCGLFEglVertexAttrib2sv = kCGLFEglVertexAttrib2svARB,
	kCGLFEglVertexAttrib3d  = kCGLFEglVertexAttrib3dARB,
	kCGLFEglVertexAttrib3dv = kCGLFEglVertexAttrib3dvARB,
	kCGLFEglVertexAttrib3f  = kCGLFEglVertexAttrib3fARB,
	kCGLFEglVertexAttrib3fv = kCGLFEglVertexAttrib3fvARB,
	kCGLFEglVertexAttrib3s  = kCGLFEglVertexAttrib3sARB,
	kCGLFEglVertexAttrib3sv = kCGLFEglVertexAttrib3svARB,
	kCGLFEglVertexAttrib4bv = kCGLFEglVertexAttrib4bvARB,
	kCGLFEglVertexAttrib4d  = kCGLFEglVertexAttrib4dARB,
	kCGLFEglVertexAttrib4dv = kCGLFEglVertexAttrib4dvARB,
	kCGLFEglVertexAttrib4f  = kCGLFEglVertexAttrib4fARB,
	kCGLFEglVertexAttrib4fv = kCGLFEglVertexAttrib4fvARB,
	kCGLFEglVertexAttrib4iv = kCGLFEglVertexAttrib4ivARB,
	
	kCGLFEglVertexAttrib4nbvARB  = kCGLFEglVertexAttrib4Nbv,
	kCGLFEglVertexAttrib4nivARB  = kCGLFEglVertexAttrib4Niv,
	kCGLFEglVertexAttrib4nsvARB  = kCGLFEglVertexAttrib4Nsv,
	kCGLFEglVertexAttrib4nubARB  = kCGLFEglVertexAttrib4Nub,
	kCGLFEglVertexAttrib4nubvARB = kCGLFEglVertexAttrib4Nubv,
	kCGLFEglVertexAttrib4NubvARB = kCGLFEglVertexAttrib4Nubv,
	kCGLFEglVertexAttrib4nuivARB = kCGLFEglVertexAttrib4Nuiv,
	kCGLFEglVertexAttrib4nusvARB = kCGLFEglVertexAttrib4Nusv,

	kCGLFEglVertexAttrib4nbv  = kCGLFEglVertexAttrib4nbvARB,
	kCGLFEglVertexAttrib4niv  = kCGLFEglVertexAttrib4nivARB,
	kCGLFEglVertexAttrib4nsv  = kCGLFEglVertexAttrib4nsvARB,
	kCGLFEglVertexAttrib4nub  = kCGLFEglVertexAttrib4nubARB,
	kCGLFEglVertexAttrib4nubv = kCGLFEglVertexAttrib4nubvARB,
	kCGLFEglVertexAttrib4nuiv = kCGLFEglVertexAttrib4nuivARB,
	kCGLFEglVertexAttrib4nusv = kCGLFEglVertexAttrib4nusvARB,
	
	kCGLFEglVertexAttrib4s   = kCGLFEglVertexAttrib4sARB,
	kCGLFEglVertexAttrib4sv  = kCGLFEglVertexAttrib4svARB,
	kCGLFEglVertexAttrib4ubv = kCGLFEglVertexAttrib4ubvARB,
	kCGLFEglVertexAttrib4uiv = kCGLFEglVertexAttrib4uivARB,
	kCGLFEglVertexAttrib4usv = kCGLFEglVertexAttrib4usvARB,
	
	kCGLFEglBindBufferRange = kCGLFEglBindBufferRangeEXT,
	kCGLFEglBindBufferBase  = kCGLFEglBindBufferBaseEXT,
	
	kCGLFEglGetActiveUniformsiv = kCGLFEglGetActiveUniformsivAPPLE,
	kCGLFEglGetUniformIndices   = kCGLFEglGetUniformIndicesAPPLE,
} CGLProfilerFunctionEnum;


#ifdef __cplusplus
}
#endif

#endif /* _CGLPROFILERFUNCTIONENUM_H */
