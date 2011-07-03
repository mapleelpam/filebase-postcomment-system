/*
 * singleton.h
 *
 *  Created on: 2011/7/4
 *      Author: maple
 */

#include <global.h>

#ifndef _COMMON_SINGLETON_H_
#define _COMMON_SINGLETON_H_

namespace common {

template< class N >
struct Singleton
{
//	Singleton()
//	{
//#if defined( _MSC_VER ) && _MSC_VER < 1200
//        int offset = (int)(N*)1 - (int)(Singleton <N>*)(N*)1;
//        m_instance = (N*)((int)this + offset);
//#else
//        m_instance = static_cast<N*>(this);
//#endif
//	}
//    ~Singleton()
//    {
//       SAFE_DELETE(m_instance);
//    }

public:
    static N* instance()
    {
        if(!m_instance)
        {
        	m_instance = new N;
        }

        return m_instance;
    }


private:
    static N* m_instance;

};

}

#endif /* SINGLETON_H_ */
