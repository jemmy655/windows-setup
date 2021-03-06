#ifndef COMPOSERSHELL_REGISTER_H
#define COMPOSERSHELL_REGISTER_H

#include <windows.h>
#include <Guiddef.h>

// {9DF9AD0B-5D99-485a-840E-858003F87478} DO NOT CHANGE
const CLSID COMPOSER_CLSID = 
{ 0x9df9ad0b, 0x5d99, 0x485a, { 0x84, 0xe, 0x85, 0x80, 0x3, 0xf8, 0x74, 0x78 } };

const PCWSTR COMPOSER_NAME = L"ComposerSetup"; // DO NOT CHANGE

const PCWSTR COMPOSER_HANDLERS[] = {
    {L"AllFileSystemObjects"},
    {L"Directory\\Background"}
};

class ComposerShellReg
{
public:
    ComposerShellReg(void);
    HRESULT Register(PCWSTR module);
    HRESULT Unregister();
private:
    HRESULT HandlersDoRegister(BOOL reg);
    HRESULT PathGetForHandler(PCWSTR handler, LPWSTR path, size_t cch);
    HRESULT PathGetForServer(LPWSTR path, size_t cch);
    HRESULT ServerRegister(PCWSTR module);
    HRESULT ServerUnregister();
    HRESULT SetKeyAndValue(PCWSTR subKey, PCWSTR valueName, PCWSTR data);

    HKEY m_RootKey;
    const PCWSTR m_ClassPath;
    wchar_t m_CLSIDStr[40];
};

#endif
