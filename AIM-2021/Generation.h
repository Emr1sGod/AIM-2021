#pragma once
#define BEFORE_DATA ".586\n.model flat, stdcall\n\nincludelib kernel32.lib\nincludelib libucrt.lib\nincludelib ../Debug/Library.lib\n"
#define TEXTMAXSIZE 255
#define ASM_FILE_PATH "..//ASM/ASM.asm"
#define ASMCYCLE "MARK"
#define ASMCYCLEOUT "MARKOUT"
#define ASMWHEN "OUTWHEN"
#define ASMWHENNOT "WHENNOT"

namespace Generation
{
	struct OneSegment {
		std::string Name;
		std::string Code;
	};
	std::string WriteSegment(OneSegment segment);

	std::string Generate(LexA::Tables);
	void GenerateFunction(int);
}