#pragma once
#include <core/smartview/smartViewParser.h>
#include <core/smartview/block/blockStringA.h>
#include <core/smartview/block/blockStringW.h>
#include <core/smartview/block/blockT.h>

namespace smartview
{
	struct VerbData
	{
		std::shared_ptr<blockT<DWORD>> VerbType = emptyT<DWORD>();
		std::shared_ptr<blockT<BYTE>> DisplayNameCount = emptyT<BYTE>();
		std::shared_ptr<blockStringA> DisplayName = emptySA();
		std::shared_ptr<blockT<BYTE>> MsgClsNameCount = emptyT<BYTE>();
		std::shared_ptr<blockStringA> MsgClsName = emptySA();
		std::shared_ptr<blockT<BYTE>> Internal1StringCount = emptyT<BYTE>();
		std::shared_ptr<blockStringA> Internal1String = emptySA();
		std::shared_ptr<blockT<BYTE>> DisplayNameCountRepeat = emptyT<BYTE>();
		std::shared_ptr<blockStringA> DisplayNameRepeat = emptySA();
		std::shared_ptr<blockT<DWORD>> Internal2 = emptyT<DWORD>();
		std::shared_ptr<blockT<BYTE>> Internal3 = emptyT<BYTE>();
		std::shared_ptr<blockT<DWORD>> fUseUSHeaders = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> Internal4 = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> SendBehavior = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> Internal5 = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> ID = emptyT<DWORD>();
		std::shared_ptr<blockT<DWORD>> Internal6 = emptyT<DWORD>();

		VerbData(const std::shared_ptr<binaryParser>& parser);
	};

	struct VerbExtraData
	{
		std::shared_ptr<blockT<BYTE>> DisplayNameCount = emptyT<BYTE>();
		std::shared_ptr<blockStringW> DisplayName = emptySW();
		std::shared_ptr<blockT<BYTE>> DisplayNameCountRepeat = emptyT<BYTE>();
		std::shared_ptr<blockStringW> DisplayNameRepeat = emptySW();

		VerbExtraData(const std::shared_ptr<binaryParser>& parser);
	};

	class VerbStream : public smartViewParser
	{
	private:
		void Parse() override;
		void ParseBlocks() override;

		std::shared_ptr<blockT<WORD>> m_Version = emptyT<WORD>();
		std::shared_ptr<blockT<DWORD>> m_Count = emptyT<DWORD>();
		std::vector<std::shared_ptr<VerbData>> m_lpVerbData;
		std::shared_ptr<blockT<WORD>> m_Version2;
		std::vector<std::shared_ptr<VerbExtraData>> m_lpVerbExtraData;
	};
} // namespace smartview