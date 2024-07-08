#include <Arduino.h>
#include <SoftwareSerial.h>

enum class EBluetoothAdapter { HC_05, HC_06 };	//HC_05 is both Master/Slave. HC_06 only Slave
enum class EATCommand { AT, AT_VERSION, AT_DEVICE_NAME, AT_BAUD, AT_PIN, AT_PARITY,	//common for both adapters
AT_RESET, AT_ROLE, AT_CMODE, AT_BIND, AT_STATE, AT_PAIR, AT_LINK,	//specific for HC-05
AT_DELETE_PAIRED, AT_DELETE_ALL_PAIRED,	AT_DISCONNECT
/*AT_IPSCAN, AT_SNIFF, AT_START_ENERGY, AT_STOP_ENERGY*/ };
enum class ECommandType { Unknown, ArrayBytes, StringCommand };

class CBluetooth
{
	public:
		// Constructors
		CBluetooth(uint8_t iPinRx, uint8_t iPinTx, EBluetoothAdapter adapter) : m_Serial(iPinRx, iPinTx)
		{
			m_adapter = adapter;
		};

		// Public methods
		void Begin(long lBauds);
		void SendATCommandHC05(EATCommand command, String sValue);
		void SendATCommandHC06(EATCommand command, String sValue);

		String DirectReceive();
		String Receive();
		void Send(String sMessage);
		
		void SendCommand(String sMessage);
		void SendCommand(byte byteX, byte byteY);
		ECommandType CommandType(String sCommand);
		int* ProcessArrayBytesCommand(String sCommand);
		String ProcessStringCommand(String sCommand);

		//Data accessor
		String GetMessage()
		{
			return m_sMessage;
		};
	private:
		// Fields
		SoftwareSerial m_Serial;
		EBluetoothAdapter m_adapter;
		String m_sMessage;

		// Private methods
};
