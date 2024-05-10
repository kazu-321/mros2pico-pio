#include <string>
#include <vector>

namespace sensor_msgs
{
namespace msg
{
class Image
{
public:
  uint32_t cntPub = 0;
  uint32_t cntSub = 0;
  uint32_t idxSerialized = 0;

  typedef std::pair<bool, uint32_t> FragCopyReturnType;

  std::string getTypeName();
  int32_t  sec;
  uint32_t nanosec;
  std::string frame_id;
  uint32_t cntPub_frame_id = 0;
  uint32_t height;
  uint32_t width;
  std::string encoding;
  uint32_t cntPub_encoding = 0;
  uint8_t is_bigendian;
  uint32_t step;
  std::vector<uint8_t> data;
  uint32_t cntPub_data = 0;

  template <class T>
  uint32_t copyPrimToFragBufLocal(uint8_t*& addrPtr,
				  const uint32_t cntPub,
				  const uint32_t size,
				  const T& data)
  {
    uint32_t lenPad = (0 == (cntPub % sizeof(T))) ?
      0 : (sizeof(T) - (cntPub % sizeof(T))); //This won't work for float128.
    if ( size < sizeof(T) ) {
      // There are no enough space.
      return 0;
    }
    // Put padding space
    for(int i = 0; i < lenPad; i++){
      *addrPtr = 0;
      addrPtr += 1;
    }
    // Store serialzed value.
    memcpy(addrPtr, &data, sizeof(T));
    addrPtr += sizeof(T);

    return sizeof(T) + lenPad;
  }

  template<class T>
  FragCopyReturnType copyArrayToFragBufLocal(uint8_t*& addrPtr,
					     const uint32_t size,
					     T& data,
					     uint32_t& cntPubMemberLocal)
  {
    uint32_t pubDataSize = data.size();
    uint32_t cntLocalFrag = 0;

    if (cntPubMemberLocal < sizeof(uint32_t)) {
      if (size < sizeof(uint32_t)) {
        return {false, 0};
      }
      memcpy(addrPtr, &pubDataSize, sizeof(uint32_t));
      addrPtr += sizeof(uint32_t);
      cntPubMemberLocal += sizeof(uint32_t);
      cntLocalFrag += sizeof(uint32_t);
    }

    uint32_t cntFrag = (cntPubMemberLocal - sizeof(uint32_t));
    uint32_t tmp = std::min(pubDataSize - cntFrag, size - cntLocalFrag);
    if (0 < tmp) {
      memcpy(addrPtr, data.data() + cntFrag, tmp);
      addrPtr += tmp;
      cntPubMemberLocal += tmp;
      cntLocalFrag += tmp;
    }

    return {(cntPubMemberLocal - sizeof(uint32_t)) >= pubDataSize, cntLocalFrag};
  }

  void resetCount()
  {
    cntPub = 0;
    cntSub = 0;
    cntPub_frame_id = 0;
    cntPub_encoding = 0;
    cntPub_data = 0;
    idxSerialized = 0;
    return;
  }

  // The code below is generated by the exsiting generator.
  uint32_t copyToBuf(uint8_t *addrPtr)
  {
    uint32_t tmpPub = 0;
    uint32_t arraySize;
    uint32_t stringSize;


    if (cntPub%4 >0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }

    memcpy(addrPtr,&sec,4);
    addrPtr += 4;
    cntPub += 4;

    memcpy(addrPtr,&nanosec,4);
    addrPtr += 4;
    cntPub += 4;

    stringSize = frame_id.size();
    memcpy(addrPtr,&stringSize,4);
    addrPtr += 4;
    cntPub += 4;
    memcpy(addrPtr,frame_id.c_str(),stringSize);
    addrPtr += stringSize;
    cntPub += stringSize;





    if (cntPub%4 > 0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }

    memcpy(addrPtr,&height
,4);
    addrPtr += 4;
    cntPub += 4;





    if (cntPub%4 > 0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }

    memcpy(addrPtr,&width
,4);
    addrPtr += 4;
    cntPub += 4;




    if (cntPub%4 >0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }
    stringSize = encoding
.size();
    memcpy(addrPtr,&stringSize,4);
    addrPtr += 4;
    cntPub += 4;
    memcpy(addrPtr,encoding
.c_str(),stringSize);
    addrPtr += stringSize;
    cntPub += stringSize;





    memcpy(addrPtr,&is_bigendian
,1);
    addrPtr += 1;
    cntPub += 1;





    if (cntPub%4 > 0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }

    memcpy(addrPtr,&step
,4);
    addrPtr += 4;
    cntPub += 4;




    {
    if (cntPub%4 >0){
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }
    arraySize = data
.size();
    memcpy(addrPtr,&arraySize,4);
    addrPtr += 4;
    cntPub += 4;




    const uint8_t* ptr = data
.data();

    for(int i=0; i<arraySize ; i++){
      memcpy(addrPtr, &(ptr[i]),4);
      addrPtr += 4;
      cntPub += 4;
    }

    }



    return cntPub;
  }

  uint32_t copyFromBuf(const uint8_t *addrPtr) {
    uint32_t tmpSub = 0;
    uint32_t arraySize;
    uint32_t stringSize;



    if (cntSub%4 >0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }
    memcpy(&sec,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;

    memcpy(&nanosec,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;

    memcpy(&stringSize, addrPtr, 4);
    addrPtr += 4;
    cntSub += 4;
    frame_id.resize(stringSize);
    memcpy(&frame_id[0],addrPtr,stringSize);
    addrPtr += stringSize;
    cntSub += stringSize;





    if (cntSub%4 > 0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }

    memcpy(&height
,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;




    if (cntSub%4 > 0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }

    memcpy(&width
,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;



    if (cntSub%4 >0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }
    memcpy(&stringSize, addrPtr, 4);
    addrPtr += 4;
    cntSub += 4;
    encoding
.resize(stringSize);
    memcpy(&encoding
[0],addrPtr,stringSize);
    addrPtr += stringSize;
    cntSub += stringSize;





    memcpy(&is_bigendian
,addrPtr,1);
    addrPtr += 1;
    cntSub += 1;




    if (cntSub%4 > 0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }

    memcpy(&step
,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;



    {
    if (cntSub%4 >0){
      for(int i=0; i<(4-(cntSub%4)) ; i++){
        addrPtr += 1;
      }
      cntSub += 4-(cntSub%4);
    }
    memcpy(&arraySize,addrPtr,4);
    addrPtr += 4;
    cntSub += 4;



    data
.reserve(arraySize);


    for(int i=0;i<arraySize;i++){
      uint32_t buf;
      memcpy(&buf,addrPtr,4);
      data
.push_back(buf);
      addrPtr += 4;
      cntSub += 4;
    }

    }



    return cntSub;
  }
  // The code above is generated by the exsiting generator.

   void memAlign(uint8_t *addrPtr){
    if (cntPub%4 > 0){
      addrPtr += cntPub;
      for(int i=0; i<(4-(cntPub%4)) ; i++){
        *addrPtr = 0;
        addrPtr += 1;
      }
      cntPub += 4-(cntPub%4);
    }
    return;
  }

  uint32_t getTotalSize(){
    uint32_t tmpCntPub = cntPub;
    cntPub = 0;
    return tmpCntPub ;
  }

  uint32_t getPubCnt()
  {
    return cntPub;
  }

  uint32_t calcRawTotalSize()
  {
    uint32_t tmp;

    tmp =
      4 +
      4 +
      ( (4 + frame_id.size()) +
	( (0 == (frame_id.size() % 4)) ?
	  0 : (4 - frame_id.size() % 4) ) ) +
      4 +
      4 +
      ( (4 + (encoding.size() + 1)) +
	( (0 == (encoding.size() + 1) % 4) ?
	  0 : (4 - (encoding.size() + 1) % 4) ) ) +
      4 +
      4 +
      data.size();

    return tmp;
  }


  uint32_t calcTotalSize()
  {
    uint32_t tmp;
    tmp = 4 // CDR encoding version.
          + calcRawTotalSize();
    tmp += ( 0 == (tmp % 4) ? // Padding
	     0 : (4 - (tmp % 4)) );
    return tmp;
  }

  FragCopyReturnType  copyToFragBuf(uint8_t *addrPtr, uint32_t size)
  {
    uint32_t totalSize = calcRawTotalSize();
    uint32_t partSize = std::min((totalSize - cntPub), size);
    uint32_t cntLocal = 0;

    // sec
    if (1 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<int32_t>(addrPtr,
					cntPub,
					size - cntLocal,
					sec);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // nanosec
    if (2 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<uint32_t>(addrPtr,
					 cntPub,
					 size - cntLocal,
					 nanosec);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // frame_id
    if (3 > idxSerialized) {
      auto ret =
	copyArrayToFragBufLocal<std::string>(addrPtr,
					     size - cntLocal,
					     frame_id,
					     cntPub_frame_id);
      cntLocal += ret.second;
      cntPub += ret.second;
      if (false == ret.first) {
	// ran out of the buffer.
	return {false, cntLocal};
      } else {
	idxSerialized ++;
      }
    }

    // height
    if (4 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<uint32_t>(addrPtr,
					 cntPub,
					 size - cntLocal,
					 height);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // width
    if (5 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<uint32_t>(addrPtr,
					 cntPub,
					 size - cntLocal,
					 width);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // encoding
    if (6 > idxSerialized) {
      auto ret =
	copyArrayToFragBufLocal<std::string>(addrPtr,
					     size - cntLocal,
					     encoding,
					     cntPub_encoding);
      cntLocal += ret.second;
      cntPub += ret.second;
      if (false == ret.first) {
	// ran out of the buffer.
	return {false, cntLocal};
      } else {
	idxSerialized ++;
      }
    }

    // is_bigendian
    if (7 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<uint8_t>(addrPtr,
					 cntPub,
					 size - cntLocal,
					 is_bigendian);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // step
    if (8 > idxSerialized) {
      auto ret =
	copyPrimToFragBufLocal<uint32_t>(addrPtr,
					 cntPub,
					 size - cntLocal,
					 step);
      if (0 == ret) {
	// ran out of the buffer.
	return {false, cntLocal};
      }
      idxSerialized ++;
      cntLocal += ret;
      cntPub += ret;
    }

    // data
    if (9 > idxSerialized) {
      auto ret =
	copyArrayToFragBufLocal<std::vector<uint8_t>>(addrPtr,
						      size - cntLocal,
						      data,
						      cntPub_data);
      cntLocal += ret.second;
      cntPub += ret.second;
      if (false == ret.first) {
	// ran out of the buffer.
	return {false, cntLocal};
      } else {
	idxSerialized ++;
      }
    }

    return {cntPub >= calcRawTotalSize(), partSize};
  }

private:
  std::string type_name = "std_sensor::msg::dds_::Image";
};
}//namspace msg
}//namespace sensor_msgs

namespace message_traits
{

template<>
struct TypeName<sensor_msgs::msg::Image*> {
  static const char* value()
  {
    return "sensor_msgs::msg::dds_::Image_";
  }
};

}
