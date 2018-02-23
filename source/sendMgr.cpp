//
// Created by Administrator on 2018/2/23 0023.
//

#include "../include/sendMgr.h"
using namespace std;

CSendMgr gSendMgr;
CSendMgr::CSendMgr() {
	mnTrdNum = 0;
	mpSendArr = NULL;
}

CSendMgr::~CSendMgr() {

}

bool CSendMgr::begin_pool(int nTrdNum) {
	mnTrdNum = nTrdNum;
	mpSendArr = new CSendTrd[nTrdNum];
	for (int i=0; i<nTrdNum; ++i) {
		mpSendArr[i].send_start();
	}

	return true;
}

bool CSendMgr::end_pool() {
	if(mpSendArr == NULL) {
		return false;
	}

	for (int i=0; i<mnTrdNum; ++i) {
		mpSendArr[i].send_start();
	}

	return true;
}

void CSendMgr::put_one_msg(std::string msg) {
	mVecMsg.push_back(msg);
}

std::string CSendMgr::get_one_msg() {
	std::string strMsg;
	vector<string>::iterator it = mVecMsg.begin();
	if(it != mVecMsg.end()) {
		strMsg = *it;
		mVecMsg.erase(it);
	} else {
		return string("0");
	}

	return strMsg;
}