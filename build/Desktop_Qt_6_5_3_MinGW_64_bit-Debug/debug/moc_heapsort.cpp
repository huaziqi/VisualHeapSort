/****************************************************************************
** Meta object code from reading C++ file 'heapsort.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../heapsort.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heapsort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSHeapSortENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHeapSortENDCLASS = QtMocHelpers::stringData(
    "HeapSort",
    "sortInfo",
    "",
    "swap",
    "contrast",
    "codesId",
    "paintInfo",
    "currentPoint",
    "QList<int>",
    "nums",
    "size",
    "tow",
    "gotV",
    "vSide",
    "judge",
    "inDown",
    "info",
    "maxn",
    "acceptData",
    "stepedSort",
    "reset"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHeapSortENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[9];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[8];
    char stringdata6[10];
    char stringdata7[13];
    char stringdata8[11];
    char stringdata9[5];
    char stringdata10[5];
    char stringdata11[4];
    char stringdata12[5];
    char stringdata13[6];
    char stringdata14[6];
    char stringdata15[7];
    char stringdata16[5];
    char stringdata17[5];
    char stringdata18[11];
    char stringdata19[11];
    char stringdata20[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHeapSortENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHeapSortENDCLASS_t qt_meta_stringdata_CLASSHeapSortENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "HeapSort"
        QT_MOC_LITERAL(9, 8),  // "sortInfo"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 4),  // "swap"
        QT_MOC_LITERAL(24, 8),  // "contrast"
        QT_MOC_LITERAL(33, 7),  // "codesId"
        QT_MOC_LITERAL(41, 9),  // "paintInfo"
        QT_MOC_LITERAL(51, 12),  // "currentPoint"
        QT_MOC_LITERAL(64, 10),  // "QList<int>"
        QT_MOC_LITERAL(75, 4),  // "nums"
        QT_MOC_LITERAL(80, 4),  // "size"
        QT_MOC_LITERAL(85, 3),  // "tow"
        QT_MOC_LITERAL(89, 4),  // "gotV"
        QT_MOC_LITERAL(94, 5),  // "vSide"
        QT_MOC_LITERAL(100, 5),  // "judge"
        QT_MOC_LITERAL(106, 6),  // "inDown"
        QT_MOC_LITERAL(113, 4),  // "info"
        QT_MOC_LITERAL(118, 4),  // "maxn"
        QT_MOC_LITERAL(123, 10),  // "acceptData"
        QT_MOC_LITERAL(134, 10),  // "stepedSort"
        QT_MOC_LITERAL(145, 5)   // "reset"
    },
    "HeapSort",
    "sortInfo",
    "",
    "swap",
    "contrast",
    "codesId",
    "paintInfo",
    "currentPoint",
    "QList<int>",
    "nums",
    "size",
    "tow",
    "gotV",
    "vSide",
    "judge",
    "inDown",
    "info",
    "maxn",
    "acceptData",
    "stepedSort",
    "reset"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHeapSortENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       5,    1,   55,    2, 0x06,    4 /* Public */,
       6,   12,   58,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    3,   83,    2, 0x0a,   19 /* Public */,
      19,    0,   90,    2, 0x0a,   23 /* Public */,
      20,    0,   91,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::Int,    7,    9,   10,    4,    3,   11,   12,   13,   14,   15,   16,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,   10,    9,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject HeapSort::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSHeapSortENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHeapSortENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHeapSortENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HeapSort, std::true_type>,
        // method 'sortInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'codesId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'paintInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'acceptData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<int> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'stepedSort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HeapSort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeapSort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sortInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->codesId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->paintInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[12]))); break;
        case 3: _t->acceptData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->stepedSort(); break;
        case 5: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HeapSort::*)(int , int );
            if (_t _q_method = &HeapSort::sortInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HeapSort::*)(int );
            if (_t _q_method = &HeapSort::codesId; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HeapSort::*)(int , QVector<int> , int , bool , bool , bool , bool , bool , bool , bool , QString , int );
            if (_t _q_method = &HeapSort::paintInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *HeapSort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeapSort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHeapSortENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HeapSort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HeapSort::sortInfo(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HeapSort::codesId(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HeapSort::paintInfo(int _t1, QVector<int> _t2, int _t3, bool _t4, bool _t5, bool _t6, bool _t7, bool _t8, bool _t9, bool _t10, QString _t11, int _t12)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
