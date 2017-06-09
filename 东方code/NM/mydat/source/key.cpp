#include "../include/GV.h"

unsigned int stateKey[256];
//处理现在输入
int GetHitKeyStateAll_2(){
    char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll( GetHitKeyStateAll_Key );
    for(int i=0;i<256;i++){
        if(GetHitKeyStateAll_Key[i]==1) stateKey[i]++;
        else                            stateKey[i]=0;
    }
    return 0;
}
//返回传入的按键编号的当前状态
int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

//保存手柄输入状态的变量
pad_t pad;

//把参数1和参数2中较大的一方传给参数1
void input_pad_or_key(int *p, int k){
	*p = *p>k ? *p : k;
}

//同时检查手柄和键盘输入的函数
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//获得手柄的输入状态
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));
	input_pad_or_key(&pad.key[configpad.up]	    ,CheckStateKey(KEY_INPUT_UP	     ));
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));
	input_pad_or_key(&pad.key[configpad.shot]	,CheckStateKey(KEY_INPUT_Z	     ));
	input_pad_or_key(&pad.key[configpad.bom]	,CheckStateKey(KEY_INPUT_X		 ));
	input_pad_or_key(&pad.key[configpad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));
	input_pad_or_key(&pad.key[configpad.change] ,CheckStateKey(KEY_INPUT_LCONTROL));
}

//返回传入的手柄的按键编号对应的输入状态。如果返回-1表示传入错误。
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("CheckStatePad偵搉偟偨抣偑晄惓偱偡\n");
		return -1;
	}
}