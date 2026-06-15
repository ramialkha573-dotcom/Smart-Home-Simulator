# 🏠 Smart Home Simulator

برنامج محاكاة منزل ذكي مكتوب بلغة C++ يحتوي على مزايا البرمجة الكائنية التوجه المتقدمة.

## ✨ المزايا الرئيسية

### 1️⃣ **البرمجة الكائنية التوجه (OOP)**
- ✅ **Classes**: فئات Device, Light, AirConditioner, Television, SmartHome
- ✅ **Objects**: إنشاء كائنات من الأجهزة المختلفة
- ✅ **Inheritance**: وراثة من Device للأجهزة الأخرى
- ✅ **Polymorphism**: استخدام Virtual Methods للدوال المختلفة
- ✅ **Encapsulation**: متغيرات خاصة وعامة

### 2️⃣ **Operator Overloading (تحميل العمليات)**
```cpp
Device* device = home[0];           // operator[]
home += new Light("Light1", 60);    // operator+=
home -= 0;                          // operator-=
cout << device;                     // operator<<
cout << home;                       // operator<<
bool result = device1 == device2;   // operator==
```

### 3️⃣ **Arrays و Collections (المصفوفات والقوائم)**
- `vector<Device*>`: قائمة ديناميكية للأجهزة
- دعم إضافة وحذف الأجهزة بسهولة

### 4️⃣ **الأجهزة المدعومة**
- 💡 **Light**: جهاز إضاءة مع تحكم السطوع (0-100%)
- ❄️ **AirConditioner**: مكيف هواء مع تحكم درجة الحرارة (16-30°C)
- 📺 **Television**: تلفاز مع تحكم الصوت والقنوات

## 🚀 كيفية التثبيت والتشغيل

### المتطلبات
- g++ compiler
- Linux/Mac/Windows (with MinGW or WSL)

### خطوات التثبيت
```bash
# استنساخ المستودع
git clone https://github.com/ramialkha573-dotcom/Smart-Home-Simulator.git
cd Smart-Home-Simulator

# تجميع البرنامج
make

# تشغيل البرنامج
make run

# أو تشغيل مباشر
./SmartHomeSimulator
```

### تنظيف ملفات التجميع
```bash
make clean
```

## 📋 الميزات والعمليات المتاحة

### 1. ➕ إضافة جهاز
```
اختر نوع الجهاز:
1. 💡 Light (60W)
2. ❄️ Air Conditioner (1500W)
3. 📺 Television (100W)
```

### 2. ❌ حذف جهاز
اختر رقم الجهاز المراد حذفه

### 3. 📋 عرض جميع الأجهزة
يعرض قائمة بجميع الأجهزة مع حالتها (ON/OFF) والمعلومات الخاصة بها

### 4. 💡 تشغيل جهاز
اختر رقم الجهاز لتشغيله

### 5. 🌙 إطفاء جهاز
اختر رقم الجهاز لإطفاءه

### 6. 🔋 تشغيل جميع الأجهزة
تشغيل كل الأجهزة في المنزل الذكي

### 7. 🔌 إطفاء جميع الأجهزة
إطفاء كل الأجهزة في المنزل الذكي

### 8. ⚡ عرض استهلاك الطاقة
يعرض قائمة بالطاقة المستهلكة لكل جهاز والمجموع الكلي

### 9. ℹ️ معلومات المنزل الذكي
عرض معلومات عن المنزل والأجهزة الموجودة

### 0. 🚪 خروج
إغلاق البرنامج

## 📁 هيكل الملفات

```
Smart-Home-Simulator/
├── Device.h              # فئة الجهاز الأساسية
├── Device.cpp
├── Light.h               # فئة الإضاءة (وراثة من Device)
├── Light.cpp
├── AirConditioner.h      # فئة المكيف (وراثة من Device)
├── AirConditioner.cpp
├── Television.h          # فئة التلفاز (وراثة من Device)
├── Television.cpp
├── SmartHome.h           # فئة المنزل الذكي
├── SmartHome.cpp
├── main.cpp              # البرنامج الرئيسي مع القائمة
├── Makefile              # ملف التجميع
└── README.md             # هذا الملف
```

## 💻 مثال على الاستخدام

```cpp
// إنشاء منزل ذكي
SmartHome home("My Smart Home");

// إنشاء أجهزة
Light* light = new Light("Living Room Light", 60);
AirConditioner* ac = new AirConditioner("Hall AC", 1500);
Television* tv = new Television("Living Room TV", 100);

// إضافة الأجهزة باستخدام Operator Overloading
home += light;
home += ac;
home += tv;

// عرض جميع الأجهزة
home.displayAllDevices();

// تشغيل جهاز معين
home[0]->turnOn();

// عرض استهلاك الطاقة
home.displayPowerUsage();

// تشغيل جميع الأجهزة
home.turnOnAllDevices();
```

## 🎯 المفاهيم المستخدمة

### Inheritance (الوراثة)
```cpp
class Light : public Device {
    // يرث جميع الخصائص والدوال من Device
    // ويضيف خصائصه الخاصة
};
```

### Polymorphism (تعدد الأشكال)
```cpp
virtual void display() const;  // في Device
void display() const override; // في Light, AC, TV
```

### Operator Overloading
```cpp
bool operator==(const Device& other) const;
Device& operator=(const Device& other);
ostream& operator<<(ostream& os, const Device& device);
```

### Encapsulation (التغليف)
```cpp
private:
    string name;
    double powerConsumption;
    bool isOn;
```

## 📊 معلومات الطاقة

| الجهاز | الطاقة |
|------|-------|
| 💡 Light | 60W |
| ❄️ Air Conditioner | 1500W |
| 📺 Television | 100W |

## 🔧 التطوير المستقبلي

- [ ] إضافة أجهزة جديدة (ثلاجة، غسالة، إلخ)
- [ ] حفظ واستعادة تكوين المنزل من ملف
- [ ] إضافة جدول زمني للأجهزة
- [ ] واجهة رسومية (GUI)
- [ ] اتصال مع الإنترنت (IoT)

## 👨‍💻 المطور

**Rami Alkha**
- GitHub: [@ramialkha573-dotcom](https://github.com/ramialkha573-dotcom)
- Email: ramialkha573@gmail.com

## 📄 الترخيص

هذا المشروع مفتوح المصدر ومتاح للاستخدام الحر.

## 🤝 المساهمة

يرجى فتح Issue أو Pull Request للمساهمة في تحسين المشروع!

---

**استمتع باستخدام برنامج المنزل الذكي! 🏠✨**
