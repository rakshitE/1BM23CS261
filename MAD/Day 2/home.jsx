// app/(tabs)/home.jsx

//Timestamp: 3:48:41 (creating bg)

import Header from '../../components/Home/Header'
import Colors from './../../constant/Colors'
import NoCourse from '../../components/Home/NoCourse'
import { db } from './../../config/firebaseConfig'
import { collection, query, where, orderBy } from 'firebase/firestore'
import { UserDetailContext, useState } from '../../context/UserDetailContext'
import { Image } from 'react-native'
//import getDocs from firebase

export default function Home() {
    
    const {userDetail, setUserDetail} = useContext(UserDetailContext);
    const [courseList, setCourseList] = useState([]);
    const [loading, setLoading] = useState(false);

    useEffect(() => {
        userDetail && GetCourseList();
    }, [userDetail])
    
    const GetCourseList = async () => {
        setLoading(true)
        setCourseList([])
        const q = query(collection(db,'Courses'), where
        ("createdBy", '==', userDetail?.email), orderBy('createdOn', 'desc'));
        const querySnapshot = await getDocs(q);

        querySnapshot.forEach((doc) => {
            //console.log("--", doc.data());
            setCourseList(prev => [...prev, doc.data()])
        })
        setLoading(false);
    }
    return (
        <FlatList
            data = {[]}
            onRefresh = {() => GetCourseList}
            refreshing = {loading}
            ListHeaderComponent={
                <View style = {{
                    flex: 1,
                    backgroundColor: Colors.WHITE
                }}>
                    <Image source = {require('./../../assets/images/wave.png')}
                        style = {{
                            position: 'absolute',
                            width: '100%',
                            height: 700
                        }}
                    />
                    <View style = {{
                padding: 20,
                paddingTop: (Platform.OS == 'ios' || Platform.OS == 'web') && 45
            }}>
                <Header />
                {courseList?.length == 0 ?
                <NoCourse /> :
                <View>
                    <CourseProgress courseList = {courseList} />
                    <PracticeSection />
                    <CourseList courseList = {courseList} />
                    

                </View>
                }

                    </View>
                </View>
            } />
        )
}