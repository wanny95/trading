class AutoTradingSystem {
public:
	explicit StockBrocker(StockBrocker* stockBrocker) : stockBrocker{ stockBrocker } {}

	void selectStockBrocker(string name) {
		if (name == "kiwer") stockBrocker = new KiwerDriver();
		else if (name == "nemo") stockBrocker =  new NemoDriver();
		else if (name == "mock") stockBrocker =  new MockDriver();
		else stockBrocker = nullptr;
	}
	
	void buyNiceTiming(std::string stockCode, int price) {
	}
	
	void sellNiceTiming(std::string stockCode, int price) {
	}

	void loginSystem(std::string ID, std::string password) {
		stockBrocker->loginSystem(ID, password);
	}

	void buyStock(std::string stockCode, int count, int price) {
		stockBrocker->buyStock(stockCode, count, price);
	}
	
	void sellStock(std::string stockCode, int count, int price) {
		stockBrocker->sellStock(stockCode, count, price);
	}
	
	int getStockPrice(std::string stockCode, int minute) {
		return stockBrocker->getStockPrice(stockCode, minute);
	}
	
private:
	StockBrocker* stockBrocker;
};

class StockBrocker {
public:
	virtual void loginSystem(std::string ID, std::string password) = 0;
	virtual void buyStock(std::string stockCode, int count, int price) = 0;
	virtual void sellStock(std::string stockCode, int count, int price) = 0;
	virtual int getStockPrice(std::string stockCode, int minute) = 0;
};

class MockDriver : public StockBrocker {
public:
	MOCK_METHOD(void, loginSystem, (std::string ID, std::string password), (override));
	MOCK_METHOD(void, buyStock, (std::string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sellStock, (std::string stockCode, int count, int price), (override));
	MOCK_METHOD(int, getStockPrice, (std::string stockCode, int minute), (override));
};

class KiwerDriver : public StockBrocker {
public:
};

class NemoDriver : public StockBrocker {
public:
};
