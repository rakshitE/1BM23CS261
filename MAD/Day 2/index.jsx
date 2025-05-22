// app/courseView/[courseId]/index.jsx

import { View, Text } from 'react-native' 
import React from 'react'
import { useLocalSearchParams } from 'expo-router'
import Intro from '../../../components/CourseView/Intro';
//import correct colors
//import { Colors } from 'react-native/Libraries/NewAppScreen';
import Chapters from '../../../components/CourseView/Chapters';
import { db } from './../../../config/firebaseConfig'
export default function CourseView() {
    
    const { courseParams, courseId, enroll } = useLocalSearchParams();
    const [course, setCourse] = useState([]);
    //const course = JSON.parse(courseParams);
    //console.log{courseId}

    useEffect(() => {
        if(!courseParams) {
            GetCourseById();
        }
        else {
            setCourse(JSON.parse(courseParams));
        }
    }, [courseId])
    
    const GetCourseById = async () => {
        const docRef = await getDoc(doc(db, 'Courses', courseId));
        const courseData = docRef.data();
        setCourse(courseData)
    }

    return course && (
        <FlatList
            data={[]}
            ListHeaderComponent = {
                <View style = {{
                    flex: 1,
                    backgroundColor: Colors.WHITE
                }}>
                    <Intro course = {course} enroll = {enroll} />
                    <Chapters course = {course} />
                </View>} />
    )
}