#pragma once

#include "CosUmd12.h"

//#include "CosUmdCommandBuffer.h"
//#include "CosAllocation.h"
//#include "CosUmdUtil.h"
//#include "CosUmdDebug.h"

//#include "CosUmdResource.h"

//#include "CosUmdShader.h"

//#include "CosUmdBlendState.h"
//#include "CosUmdRasterizerState.h"
//#include "CosUmdDepthStencilState.h"

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

class CosUmd12Adapter;

#if 0
class CosUmdRenderTargetView;
class CosUmdDepthStencilView;
class CosUmdShader;
class CosUmdElementLayout;

class CosUmdSampler;
class CosUmdShaderResourceView;
class CosUmdUnorderedAccessView;

typedef union _CosUmdDeviceFlags
{
    struct
    {
        UINT    m_hasDrawCall       : 1;    // Command buffer has draw call
    };

    UINT        m_value;
} CosUmdDeviceFlags;

#endif

extern D3D12DDI_DEVICE_FUNCS_CORE_0033 g_CosUmd12Device_Ddi_0033;
extern D3D12DDI_COMMAND_LIST_FUNCS_3D_0033 g_CosUmd12CommandList_Ddi_0033;   // TODO: Move to CosUmd12CommandList.h
extern D3D12DDI_COMMAND_LIST_FUNCS_3D_0033 g_CosUmd12ComputeCommandList_Ddi_0033;   // TODO: Move to CosUmd12ComputeCommandList.h
extern D3D12DDI_COMMAND_QUEUE_FUNCS_CORE_0001 g_CosUmd12CommandQueue_Ddi_0001; // TODO: Move to CosUmd12CommandQueue.h
extern DXGI1_4_DDI_BASE_FUNCTIONS g_CosUmd12Dxgi_Ddi; // TODO: Move to CosUmd12Dxgi.h
extern D3D12DDI_EXTENDED_FEATURES_FUNCS_0020 g_CosUmd12ExtendedFeatures_Ddi_0020;

class CosUmd12Device
{
public:
    explicit CosUmd12Device( CosUmd12Adapter* pAdapter, const D3D12DDIARG_CREATEDEVICE_0003* pArgs);
    ~CosUmd12Device();

    void Standup();
    void Teardown();

    static CosUmd12Device* CastFrom( D3D10DDI_HDEVICE );
    static CosUmd12Device* CastFrom( DXGI_DDI_HDEVICE );
    D3D10DDI_HDEVICE CastTo() const;


public:

    CosUmd12Adapter*                m_pAdapter;
    UINT                            m_Interface;
    D3D12DDI_HRTDEVICE              m_hRTDevice;

    const D3D12DDI_CORELAYER_DEVICECALLBACKS_0003*   m_pUMCallbacks;
    const D3DDDI_DEVICECALLBACKS*   m_pKMCallbacks;

};

inline CosUmd12Device* CosUmd12Device::CastFrom(D3D10DDI_HDEVICE hDevice)
{
    return static_cast< CosUmd12Device* >(hDevice.pDrvPrivate);
}

inline CosUmd12Device* CosUmd12Device::CastFrom(DXGI_DDI_HDEVICE hDevice)
{
    return reinterpret_cast< CosUmd12Device* >(hDevice);
}

inline D3D10DDI_HDEVICE CosUmd12Device::CastTo() const
{
    return MAKE_D3D10DDI_HDEVICE(const_cast< CosUmd12Device* >(this));
}
