#pragma once

class CWaitTimer
{
public:
	CWaitTimer(DWORD nDuration)
	{
		m_nDuration = nDuration;
		m_nStartTime = GetTickCount();
	}

	~CWaitTimer()
	{
	}

	DWORD GetRemainTime()
	{
		DWORD nElapsed = 0; 
		nElapsed = GetTickCount() - m_nStartTime;
		if (nElapsed > m_nDuration)
            return 0;
		else
			return m_nDuration - nElapsed;
	}

	void Reset()
	{
		m_nStartTime = GetTickCount();
	}

	void Reset(DWORD nDuration)
	{
		m_nDuration = nDuration;
		m_nStartTime = GetTickCount();
	}

private:
	DWORD m_nStartTime;
	DWORD m_nDuration;
};
