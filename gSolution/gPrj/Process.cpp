// Process.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "Process.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}


// CProcess 멤버 함수

int CProcess::getStarInfo(CImage* pImage, int nTh)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0;
	for (int k = 0; k < nWidth*nHeight; k++) {
		if (fm[k] > nTh)
			nSum++;
	}
	return nSum;
}

int CProcess::getStarInfo(CImage* pImage, int nTh, CRect rect)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j*nPitch + i] > nTh) {
				nSum++;
			}
		}
	}
	return nSum;
}

